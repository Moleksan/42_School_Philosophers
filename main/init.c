/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:35:48 by moleksan          #+#    #+#             */
/*   Updated: 2025/04/07 00:24:50 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/philos.h"

int	init_sim_param(t_sim *program, int num_of_philos, char **av)
{
	int	i;

	program->sim_end = 0;
	program->philos = malloc(sizeof(t_info) * num_of_philos);
	if (!program->philos)
		return (write(2, "Memory allocation failed for philosophers\n", 41), 1);
	if (pthread_mutex_init(&program->log_mutex, NULL) != 0)
		return (write(2, "Mutex init failed: log_mutex\n", 30), 1);
	if (pthread_mutex_init(&program->death_mutex, NULL) != 0)
		return (write(2, "Mutex init failed: death_mutex\n", 32), 1);
	if (pthread_mutex_init(&program->meal_mutex, NULL) != 0)
		return (write(2, "Mutex init failed: meal_mutex\n", 31), 1);
	program->forks = malloc(sizeof(pthread_mutex_t) * num_of_philos);
	if (!program->forks)
		return (write(2, "Memory allocation failed for forks\n", 35), 1);
	i = 0;
	while (i < num_of_philos)
	{
		if (pthread_mutex_init(&program->forks[i], NULL) != 0)
			return (write(2, "Mutex init failed: fork\n", 24), 1);
		i++;
	}
	init_philo_info(program->philos, av);
	init_mutx_frk(program->philos, program, program->forks, num_of_philos);
	return (0);
}

void	init_philo_info(t_info *philos, char **argv)
{
	int	i;
	int	total_philos;

	i = 0;
	total_philos = ft_atoi(argv[1]);
	while (i < total_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].time_to_die = ft_atoi(argv[2]);
		philos[i].time_to_eat = ft_atoi(argv[3]);
		philos[i].time_to_sleep = ft_atoi(argv[4]);
		philos[i].total_philos = total_philos;
		philos[i].start_time = get_time();
		philos[i].last_meal_time = philos[i].start_time;
		if (argv[5])
		{
			philos[i].required_meals = ft_atoi(argv[5]);
		}
		else
		{
			philos[i].required_meals = -1;
		}
		i++;
	}
}

void	init_mutx_frk(
		t_info *philos,
		t_sim *simulation,
		pthread_mutex_t *forks,
		int total_philos)
{
	int	i;

	i = 0;
	while (i < total_philos)
	{
		philos[i].is_eating = 0;
		philos[i].log_mutex = &simulation->log_mutex;
		philos[i].death_mutex = &simulation->death_mutex;
		philos[i].meal_mutex = &simulation->meal_mutex;
		philos[i].simulation_end = &simulation->sim_end;
		philos[i].left_fork = &forks[i];
		if (i == total_philos - 1)
		{
			philos[i].right_fork = &forks[0];
		}
		else
		{
			philos[i].right_fork = &forks[i + 1];
		}
		i++;
	}
}
