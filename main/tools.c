/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:27:16 by moleksan          #+#    #+#             */
/*   Updated: 2025/04/07 00:41:05 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/philos.h"

void	destroy_all(t_sim *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&program->log_mutex);
	pthread_mutex_destroy(&program->meal_mutex);
	pthread_mutex_destroy(&program->death_mutex);
	while (i < program->philos[0].total_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
		usleep(300);
	return (0);
}

size_t	get_time(void)
{
	struct timeval	time;
	size_t			ms;

	gettimeofday(&time, NULL);
	ms = time.tv_sec * 1000;
	ms += time.tv_usec / 1000;
	return (ms);
}

void	print_action(t_info *philo, const char *action)
{
	size_t	time;
	int		sim_ended;

	time = get_time() - philo->start_time;
	pthread_mutex_lock(philo->death_mutex);
	sim_ended = *philo->simulation_end;
	pthread_mutex_unlock(philo->death_mutex);
	if (!sim_ended)
	{
		pthread_mutex_lock(philo->log_mutex);
		if (ft_strcmp(action, "take_fork") == 0)
			printf("%zu %d has taken a fork\n", time, philo->id);
		else if (ft_strcmp(action, "eat") == 0)
			printf("%zu %d is eating\n", time, philo->id);
		else if (ft_strcmp(action, "sleep") == 0)
			printf("%zu %d is sleeping\n", time, philo->id);
		else if (ft_strcmp(action, "think") == 0)
			printf("%zu %d is thinking\n", time, philo->id);
		else if (ft_strcmp(action, "dead") == 0)
			printf("%zu %d is dead\n", time, philo->id);
		pthread_mutex_unlock(philo->log_mutex);
	}
}
