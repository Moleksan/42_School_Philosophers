/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:16:02 by moleksan          #+#    #+#             */
/*   Updated: 2025/04/07 15:07:46 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/philos.h"

void	take_forks_and_eat(t_info *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, "take_fork");
	if (philo->total_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		print_action(philo, "dead");
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_lock(philo->death_mutex);
		*philo->simulation_end = 1;
		pthread_mutex_unlock(philo->death_mutex);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "take_fork");
	philo->is_eating = 1;
	print_action(philo, "eat");
	pthread_mutex_lock(philo->meal_mutex);
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_mutex);
	ft_usleep(philo->time_to_eat);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	rest_and_think(t_info *philo)
{
	print_action(philo, "sleep");
	ft_usleep(philo->time_to_sleep);
	print_action(philo, "think");
}

void	*routine(void *args)
{
	t_info	*philo;

	philo = (t_info *)args;
	if (philo->id % 2)
	{
		ft_usleep(philo->time_to_eat * 0.9 + 1);
	}
	while (1)
	{
		pthread_mutex_lock(philo->death_mutex);
		if (*philo->simulation_end == 1)
		{
			pthread_mutex_unlock(philo->death_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(philo->death_mutex);
		take_forks_and_eat(philo);
		if (*philo->simulation_end == 0)
			rest_and_think(philo);
	}
	return (args);
}

int	threads_wait(t_sim *sim)
{
	int	i;

	if (pthread_join(sim->check, NULL) != 0)
		destroy_all(sim);
	i = 0;
	while (i < sim->philos[0].total_philos)
	{
		if (pthread_join(sim->philos[i].thread, NULL) != 0)
			destroy_all(sim);
		i++;
	}
	return (0);
}
