/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:09:12 by moleksan          #+#    #+#             */
/*   Updated: 2024/12/21 15:20:44 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// t_philosopher	*init_philosophers(t_simulation *simulation)
// {
// 	t_philosopher	*philosophers;
// 	int				i;

// 	philosophers = malloc(sizeof(t_philosopher) * simulation
// 			->philosophers_count);
// 	if (!philosophers)
// 	{
// 		printf("Error: Memory allocation failed for philosophers.\n");
// 		return (NULL);
// 	}
// 	i = -1;
// 	while (++i < simulation->philosophers_count)
// 	{
// 		philosophers[i].start_time = 0;
// 		philosophers[i].philosopher_id = i + 1;
// 		philosophers[i].thread_id = 0;
// 		philosophers[i].last_meal_time = 0;
// 		philosophers[i].left_fork = &simulation->forks[i];
// 		if (philosophers[i].philosopher_id == simulation->philosophers_count)
// 		{
// 			philosophers[i].right_fork = &simulation->forks[0];
// 		}
// 		else
// 		{
// 			philosophers[i].right_fork = &simulation->forks[i + 1];
// 		}
// 		philosophers[i].simulation_params = simulation;
// 		philosophers[i].meal_count = 0;
// 	}
// 	return (philosophers);
// }

t_philosopher	*allocate_philosophers(t_simulation *simulation)
{
	t_philosopher	*philo;

	philo = malloc(sizeof(t_philosopher) * simulation->philosophers_count);
	if (!philo)
	{
		printf("Error: Memory allocation failed for philosophers.\n");
		return (NULL);
	}
	return (philo);
}

void	prep_philosopher(t_philosopher *philo, t_simulation *sim, int id)
{
	philo->start_time = 0;
	philo->philosopher_id = id + 1;
	philo->thread_id = 0;
	philo->last_meal_time = 0;
	philo->left_fork = &sim->forks[id];
	if (philo->philosopher_id == sim->philosophers_count)
		philo->right_fork = &sim->forks[0];
	else
		philo->right_fork = &sim->forks[id + 1];
	philo->simulation_params = sim;
	philo->meal_count = 0;
}

t_philosopher	*init_philosophers(t_simulation *simulation)
{
	t_philosopher	*philosophers;
	int				i;

	philosophers = allocate_philosophers(simulation);
	if (!philosophers)
		return (NULL);
	i = -1;
	while (++i < simulation->philosophers_count)
	{
		prep_philosopher(&philosophers[i], simulation, i);
	}
	return (philosophers);
}

t_simulation	*init_sim_data(char **argv)
{
	t_simulation	*simulation;

	simulation = malloc(sizeof(t_simulation));
	if (simulation == NULL)
		return (NULL);
	simulation->print_lock = malloc(sizeof(pthread_mutex_t));
	if (simulation->print_lock == NULL)
	{
		free(simulation);
		return (NULL);
	}
	simulation->forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	if (simulation->forks == NULL)
	{
		free(simulation->print_lock);
		free(simulation);
		return (NULL);
	}
	simulation->dying_time = ft_atoi(argv[2]);
	simulation->eating_time = ft_atoi(argv[3]);
	simulation->sleeping_time = ft_atoi(argv[4]);
	simulation->has_check_sum = 0;
	simulation->eaten_count = 0;
	if (argv[5])
	{
		simulation->has_check_sum = 1;
		simulation->eating_count = ft_atoi(argv[5]);
	}
	simulation->philosophers_count = ft_atoi(argv[1]);
	simulation->is_ready = 0;
	simulation->is_over = 0;
	return (simulation);
}

void	run_threads(t_philosopher *philosophers, t_simulation *simulation)
{
	int	i;

	i = -1;
	while (++i < simulation->philosophers_count)
	{
		pthread_mutex_init(philosophers[i].left_fork, NULL);
	}
	pthread_mutex_init(simulation->print_lock, NULL);
	create_threads(philosophers);
	check_threads(philosophers);
}
