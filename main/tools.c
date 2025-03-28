/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:30:11 by moleksan          #+#    #+#             */
/*   Updated: 2025/03/28 15:00:32 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_head.h"

// void ft_my_sleep(uint64_t duration)
// {
//     struct timeval tv;
//     uint64_t time_start, time_elapsed;

//     // Получаем текущее время в миллисекундах
//     gettimeofday(&tv, NULL);
//     time_start = tv.tv_sec * 1000 + tv.tv_usec / 1000;

//     // Засыпаем до тех пор, пока не пройдет нужное количество времени
//     while (1)
//     {
//         usleep(150);  // Немного приостанавливаем выполнение
//         gettimeofday(&tv, NULL);
//         time_elapsed = tv.tv_sec * 1000 + tv.tv_usec / 1000;

//         if (time_elapsed - time_start >= duration)
//             break;
//     }
// }

// static long int	time_ms(void)
// {
// 	struct timeval	tv;

// 	gettimeofday(&tv, NULL);
// 	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
// }

// // sleeps for the time, indicated by variable time in ms
// // usleep > 10 leads 2 ft_msleep  delays, 1 ms for every 200 ms twice in 5 cases
// void	ft_msleep(long int time)
// {
// 	long int	start;

// 	start = time_ms();
// 	while (1)
// 	{
// 		usleep(150);
// 		if (time_ms() - start >= time)
// 			break ;
// 	}
// }

// // returns ms passed since the time given as the argument
// long	get_time(struct timeval time)
// {
// 	struct timeval	now;
// 	int				diff;

// 	gettimeofday(&now, NULL);
// 	diff = (now.tv_sec * 1000 + now.tv_usec / 1000) - (time.tv_sec * 1000
// 			+ time.tv_usec / 1000);
// 	return (diff);
// }