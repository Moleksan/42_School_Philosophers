/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:29:27 by moleksan          #+#    #+#             */
/*   Updated: 2025/04/07 14:56:37 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/philos.h"

int	threads_start(t_sim *sim)
{
	int	i;

	if (pthread_create(&sim->check, NULL, &control, sim) != 0)
	{
		destroy_all(sim);
		return (1);
	}
	i = 0;
	while (i < sim->philos[0].total_philos)
	{
		if (pthread_create(&sim->philos[i].thread, NULL,
				&routine, &sim->philos[i]) != 0)
		{
			destroy_all(sim);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*control(void *args)
{
	t_sim	*ph;

	ph = (t_sim *)args;
	while (1)
	{
		if (if_dead(ph->philos) == 1 || if_ate(ph->philos) == 1)
		{
			return (NULL);
		}
	}
}

int	if_ate(t_info *philos)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philos[0].required_meals == -1)
		return (0);
	while (i < philos[0].total_philos)
	{
		pthread_mutex_lock(philos[i].meal_mutex);
		if (philos[i].meals_eaten >= philos[i].required_meals
			&& philos[i].is_eating == 0)
			finished_eating++;
		pthread_mutex_unlock(philos[i].meal_mutex);
		i++;
	}
	if (finished_eating == philos[0].total_philos)
	{
		pthread_mutex_lock(philos[0].death_mutex);
		*philos->simulation_end = 1;
		pthread_mutex_unlock(philos[0].death_mutex);
		return (1);
	}
	return (0);
}

int	philosopher_dead(t_info *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_mutex);
	if (get_time() - philo->last_meal_time >= time_to_die
		&& philo->is_eating == 0)
		return (pthread_mutex_unlock(philo->meal_mutex), 1);
	pthread_mutex_unlock(philo->meal_mutex);
	return (0);
}

int	if_dead(t_info *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].total_philos)
	{
		if (philosopher_dead(&philos[i], philos[i].time_to_die))
		{
			print_action(philos, "dead");
			pthread_mutex_lock(philos[0].death_mutex);
			*philos->simulation_end = 1;
			pthread_mutex_unlock(philos[0].death_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}
