/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:16:14 by moleksan          #+#    #+#             */
/*   Updated: 2025/03/28 12:37:28 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_head.h"

void singl_philo_init(t_indv *ph_arr, int id, t_sim *shared_data)
{

    printf("singl_philo_init - Initializing philosopher %d...\n", id);
    ph_arr->lt_fork = &shared_data->forks[id - 1];
    
    if (id == shared_data->ttl_philo)
    {
        ph_arr->rt_fork = &shared_data->forks[0];
    }
    else
    {
        ph_arr->rt_fork = &shared_data ->forks[id];
    }

    ph_arr->shared_data = shared_data;
    ph_arr->times_eaten = 0;
    

    ph_arr->philo_id = id;
    ph_arr->start_time = 0;
    ph_arr->thread_id = 0;
    ph_arr->last_meal = 0;

    printf("Philosopher %d initialized: Left fork %p, Right fork %p\n", 
        id, (void*)ph_arr->lt_fork, (void*)ph_arr->rt_fork);

}

void philo_in(t_indv *ph, t_sim *shared_data)
{
    printf("philo_in - Starting philosopher initialization...\n");
    int i;
    
    i = 0;
    while(i < shared_data->ttl_philo)
    {
        singl_philo_init(&ph[i], i + 1, shared_data);
        i++;
    }
    printf("All philosophers initialized successfully.\n");

    // for (i = 0; i < shared_data->ttl_philo; i++)
    // {
    //     void print_philosopher_info(t_indv *philo, FILE *file);
    // }
}