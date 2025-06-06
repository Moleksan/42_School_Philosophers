/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:43:31 by moleksan          #+#    #+#             */
/*   Updated: 2025/04/07 13:52:08 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/philos.h"

int	main(int ac, char **av)
{
	t_sim	sim;

	if (args_valid(ac, av))
	{
		write(1, "Wrong input\n", 12);
		return (1);
	}
	if (init_sim_param(&sim, ft_atoi(av[1]), av) == 1)
	{
		destroy_all(&sim);
		return (1);
	}
	if (threads_start(&sim) == 1)
	{
		destroy_all(&sim);
		return (1);
	}
	if (threads_wait(&sim) != 0)
	{
		destroy_all(&sim);
		return (1);
	}
	destroy_all(&sim);
	return (0);
}
