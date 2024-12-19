#include "philosophers.h"

void philo_eat(t_philosopher *p)
{
    pthread_mutex_lock(p->left_fork);
    output_status(p, 1);

    pthread_mutex_lock(p->right_fork);
    output_status(p, 6);

    p->last_meal_time = current_time();
    p->meal_count++;

    output_status(p, 2);

    ft_usleep(p->simulation_params->eating_time);

    pthread_mutex_unlock(p->left_fork);
    pthread_mutex_unlock(p->right_fork);
}

void *routine(void *phil)
{
    t_philosopher *p;

    p = (t_philosopher *)phil;
    while (!(p->simulation_params->is_ready))
        continue ;

    if (p->philosopher_id % 2)
        ft_usleep(p->simulation_params->eating_time * 0.9 + 1);

    while (!(p->simulation_params->is_over))
    {
        philo_eat(p);

        pthread_mutex_lock(p->simulation_params->print_lock);
        if (p->simulation_params->has_check_sum
            && p->meal_count == p->simulation_params->eating_count)
        {
            p->simulation_params->eaten_count++;
            pthread_mutex_unlock(p->simulation_params->print_lock);
            return (NULL);
        }
        pthread_mutex_unlock(p->simulation_params->print_lock);

        output_status(p, 3);
        ft_usleep(p->simulation_params->sleeping_time);
        output_status(p, 4);
    }
    return (NULL);
}


void join_threads(t_philosopher *philosophers)
{
    int i;

    i = -1;
    while (++i < philosophers->simulation_params->philosophers_count)
    {
        pthread_join(philosophers[i].thread_id, (void *)&philosophers[i]);
    }
}

void create_threads(t_philosopher *philosophers)
{
    int         i;
    long int    t;

    i = -1;
    while (++i < philosophers->simulation_params->philosophers_count)
    {
        pthread_create(&philosophers[i].thread_id, NULL, &routine, &philosophers[i]);
    }
    i = -1;
    t = current_time();
    while (++i < philosophers->simulation_params->philosophers_count)
    {
        philosophers[i].start_time = t;
        philosophers[i].last_meal_time = t;
    }
    philosophers->simulation_params->is_ready = 1;
}
