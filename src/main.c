/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:34:38 by moleksan          #+#    #+#             */
/*   Updated: 2024/12/21 14:56:37 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_input(int ac, char **av)
{
	int	is_valid;
	int	i;
	int	max_args;

	is_valid = 1;
	i = 0;
	if (ac != 5 && ac != 6)
	{
		print_input_error();
		return (0);
	}
	if (ac == 6)
		max_args = 5;
	else
		max_args = 4;
	while (i < max_args)
	{
		if (!validate_argument(av[i + 1], i))
			is_valid = 0;
		i++;
	}
	return (is_valid);
}

int	main(int ac, char **av)
{
	t_simulation	*sim;
	t_philosopher	*philo;

	sim = NULL;
	philo = NULL;
	if (!(check_input(ac, av)))
	{
		return (0);
	}
	if (!(sim = init_sim_data(av)))
		return (0);
	if (!(philo = init_philosophers(sim)))
	{
		free_simulation(sim);
		return (1);
	}
	run_threads(philo, sim);
	join_threads(philo);
	cleanup_sim(philo);
	return (0);
}
