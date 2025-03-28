/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:11:45 by moleksan          #+#    #+#             */
/*   Updated: 2025/03/28 15:10:04 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/philo_head.h"  // Include the necessary header file



void ft_my_sleep(uint64_t duration)
{
    struct timeval tv;
    uint64_t time_start, time_elapsed;
    
    gettimeofday(&tv, NULL);
    time_start = tv.tv_sec * 1000 + tv.tv_usec / 1000;

    printf("Starting sleep for %lu milliseconds...\n", duration);
    printf("Initial time: %lu milliseconds\n", time_start);


    while (1)
    {
        usleep(1500);  
        gettimeofday(&tv, NULL);
        time_elapsed = tv.tv_sec * 1000 + tv.tv_usec / 1000;

        printf("Elapsed time: %lu milliseconds\n", time_elapsed - time_start);

        if (time_elapsed - time_start >= duration)
        {
            printf("Sleep complete! Total elapsed time: %lu milliseconds\n", time_elapsed - time_start);
            break;
        }
    }
} 

int main(int ac, char **av)
{
    t_sim *sim;
    t_indv *philo;
    int ret_val;

    sim = NULL;
    philo = NULL;
    //printf("Validating arguments in main...\n");
    ret_val = args_valid(ac, av);
    
    if (!ret_val)
    {
        err_msg();
        return (1);
    }
    //printf("IN MAIN Arguments valid! Initializing simulation...\n");
    philo =  init_data_philo(av, &sim);
    if(!philo)
    {
        printf("Failed to initialisation philosophers .\n");
        return (1);
    }

    philo_in(philo, sim);
    
    debug_info(sim, philo);
    printf("Simulation and philosophers successfully initialized! in main🎉\n");

    ft_my_sleep(5);


}
