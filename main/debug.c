/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:06:29 by moleksan          #+#    #+#             */
/*   Updated: 2025/03/28 14:51:49 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_head.h"


void print_philosopher_info(t_indv *philo, FILE *file)
{
    fprintf(file, "\n--- Philosopher %d ---\n", philo->philo_id);
    fprintf(file, "Left Fork: %p\n", (void*)philo->lt_fork);
    fprintf(file, "Right Fork: %p\n", (void*)philo->rt_fork);
    fprintf(file, "Times Eaten: %d\n", philo->times_eaten);
    fprintf(file, "Start Time: %ld\n", philo->start_time);
    fprintf(file, "Last Meal: %ld\n", philo->last_meal);
    fprintf(file, "Thread ID: %lu\n", philo->thread_id);
    fprintf(file, "Shared Data Address: %p\n", (void*)philo->shared_data);
}

void print_simulation_info(t_sim *sim, FILE *file)
{
    fprintf(file, "\n--- Simulation Data ---\n");
    fprintf(file, "Total Philosophers: %d\n", sim->ttl_philo);
    fprintf(file, "Time to Die: %d\n", sim->time_tdie);
    fprintf(file, "Time to Eat: %d\n", sim->time_teat);
    fprintf(file, "Time to Sleep: %d\n", sim->time_tsleep);
    fprintf(file, "Meals Required: %d\n", sim->meals_reqrd);
    fprintf(file, "Simulation Ready: %d\n", sim->sim_ready);
    fprintf(file, "Simulation End: %d\n", sim->sim_end);
    fprintf(file, "All Full: %d\n", sim->all_full);
    fprintf(file, "Meals Eaten: %d\n", sim->meals_eaten);
    fprintf(file, "Mutex Log Address: %p\n", (void*)sim->log_mutex);
    fprintf(file, "Forks Address: %p\n", (void*)sim->forks);
}

void debug_info(t_sim *sim, t_indv *philos)
{
    FILE *file = fopen("debug_log.txt", "w");
    if (!file)
    {
        printf("Error: Could not open the file for writing.\n");
        return;
    }

    print_simulation_info(sim, file);

    for (int i = 0; i < sim->ttl_philo; i++)
    {
        print_philosopher_info(&philos[i], file);
    }

    fclose(file);
    printf("Debugging information has been written to debug_log.txt.\n");
}
