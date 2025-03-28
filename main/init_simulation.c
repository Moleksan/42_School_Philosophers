/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:00:42 by moleksan          #+#    #+#             */
/*   Updated: 2025/03/28 11:58:19 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_head.h"

t_sim *calloc_sim(int ttl_philo)
{
   // printf("calloc_sim - Allocating memory for simulation structure...\n");
    t_sim *simulation = calloc(1, sizeof(t_sim));
    if(!simulation)
        return (NULL);

    simulation->log_mutex = calloc(1, sizeof(pthread_mutex_t));
    simulation->forks = calloc(ttl_philo, sizeof(pthread_mutex_t));

    if (!simulation->log_mutex || !simulation->forks)
    {
        printf("Memory allocation for mutexes failed.\n");
        free(simulation->log_mutex);
        free(simulation->forks);
        free(simulation);
        return (NULL);
    }

    //printf("Memory successfully allocated for simulation in  calloc_sim \n");
    return (simulation);
}

t_sim *init_sim(char **av)
{
    //printf("init_sim - Initializing simulation with provided arguments...\n");
    t_sim *simulation;
    int ttl_p;

    ttl_p = ft_atoi(av[1]);
   simulation = calloc_sim(ttl_p);
   if (!simulation)
   {
        printf("Simulation initialization failed.\n");
        return (NULL);
   }    
    simulation->ttl_philo = ttl_p;
    simulation->time_tdie = ft_atoi(av[2]);
    simulation->time_teat = ft_atoi(av[3]);
    simulation->time_tsleep = ft_atoi(av[4]);
    simulation->sim_ready = 0;
    simulation->sim_end = 0;
    simulation->all_full = 0;
    simulation->meals_eaten = 0;
    
    if(av[5])
    {
        simulation->meals_reqrd = ft_atoi(av[5]);
    }
    else
    {
        simulation->meals_reqrd = -1;
    }
        //printf("  Philosophers: %d\n  Time to die: %d\n  Time to eat: %d\n  Time to sleep: %d\n  Meals required: %d\n",simulation->ttl_philo, simulation->time_tdie, simulation->time_teat, simulation->time_tsleep, simulation->meals_reqrd);
        
    return (simulation);
}

t_indv *init_data_philo(char **av, t_sim **data)
{
    //printf("init_data_philo - Allocating memory for philosophers...\n");
    t_indv *philo;
    int ttl_ph;
    
    ttl_ph = ft_atoi(av[1]);
    philo = malloc(sizeof(t_indv) * ttl_ph);
    if (!philo)
    {
        printf("Mem allocation for philo failed.\n");
        return (NULL);
    }
    
    *data = init_sim(av);
    if (!(*data))
    {
        printf("Data parsing failed\n");
        free(philo);
        return (NULL);
    }  

    // printf("Successfully allocated philosophers in init_data_philo .\n");
    return philo;
}