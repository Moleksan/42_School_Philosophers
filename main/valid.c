/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:12:14 by moleksan          #+#    #+#             */
/*   Updated: 2025/03/26 16:01:40 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_head.h"

int ft_atoi(const char *str)
{
    int res = 0;
    int sign = 1;

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

int is_num(char *av)
{
    int i = 0;

    while (av[i])
    {
        if (av[i] < '0' || av[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int args_valid(int ac, char **av)
{
    int i = 1;

    if (ac != 5 && ac != 6)
        return (0);

    while (av[i])
    {
        if (!is_num(av[i]))  // Fixed the logic here
            return (0);
        i++;
    }

    i = 1;
    while (i <= 4)
    {
        if (ft_atoi(av[i]) <= 0)
            return (0);
        i++;
    }

    if (av[5] && ft_atoi(av[5]) <= 0)  // Fixed the logic here
        return (0);

    return (1);
}

void err_msg(void)
{
    printf(BACKGROUND_CYAN SAD_FACE " Wrong input! " RESET
           "Usage: ./philo  \nnumber_of_philosophers  \ntime_to_die   \ntime_to_eat   \ntime_to_sleep\n"
           "[number_of_times_each_philosopher_must_eat]\n");
}
