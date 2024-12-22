/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:06:32 by moleksan          #+#    #+#             */
/*   Updated: 2024/12/21 15:00:39 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_positive_integer(const char *str)
{
	if (!str || *str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = sign * -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

int	validate_argument(const char *arg)
{
	if (!is_positive_integer(arg) || ft_atoi(arg) <= 0)
	{
		print_input_error();
		return (0);
	}
	return (1);
}

void	print_input_error(void)
{
	printf(RED "Error: Incorrect number of arguments.\n" RESET);
	printf("Usage:\n");
	printf("  ./philo [number_of_philosophers] [time_to_die]");
	printf(" [time_to_eat] [time_to_sleep] [number_of_meals (optional)]\n");
}
