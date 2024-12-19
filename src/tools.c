#include "philosophers.h"

uint64_t	current_time(void)
{
	uint64_t		milliseconds;
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

void	ft_usleep(long int time)
{
	long int	start_time;

	start_time = current_time();
	while ((current_time() - start_time) < (unsigned long long) time)
		usleep(150);
}


void output_status(t_philosopher *p, int i)
{
    pthread_mutex_lock(p->simulation_params->print_lock);

    if (p->simulation_params->is_over)
    {
        pthread_mutex_unlock(p->simulation_params->print_lock);
        return;
    }

    if (i == 1)
        printf("%s%llu %d has taken left fork%s\n", PURPLE,
            current_time() - p->start_time, p->philosopher_id, RESET);
    else if (i == 2)
        printf("%s%llu %d is eating%s\n", GREEN, current_time() - p->start_time,
            p->philosopher_id, RESET);
    else if (i == 3)
        printf("%s%llu %d is sleeping%s\n", BLUE, current_time() - p->start_time,
            p->philosopher_id, RESET);
    else if (i == 4)
        printf("%s%llu %d is thinking%s\n", YELLOW, current_time() - p->start_time,
            p->philosopher_id, RESET);
    else if (i == 5)
        printf("%s%llu %d died%s\n", RED, current_time() - p->start_time,
            p->philosopher_id, RESET);
    else if (i == 6)
        printf("%s%llu %d has taken right fork%s\n", PINK,
            current_time() - p->start_time, p->philosopher_id, RESET);

    pthread_mutex_unlock(p->simulation_params->print_lock);
}

void cleanup_sim(t_philosopher *p)
{
    int i;

    i = -1;
    while (++i < p->simulation_params->philosophers_count)
    {
        pthread_mutex_destroy(p[i].left_fork);
        pthread_mutex_destroy(p[i].right_fork);
    }

    pthread_mutex_destroy(p->simulation_params->print_lock);

    free(p->simulation_params->print_lock);
    free(p->simulation_params->forks);
    free(p->simulation_params); 
    free(p); 
}

int check_death(t_philosopher *p)
{
    long int now;

    pthread_mutex_lock(p->simulation_params->print_lock);
    now = current_time() - p->last_meal_time;
    if (now >= p->simulation_params->dying_time)
    {
        pthread_mutex_unlock(p->simulation_params->print_lock);
        output_status(p, 5);
        pthread_mutex_unlock(p->left_fork);
        pthread_mutex_unlock(p->right_fork);
        return (1);
    }
    pthread_mutex_unlock(p->simulation_params->print_lock);
    return (0);
}

void check_threads(t_philosopher *p)
{
    int i;

    while (!p->simulation_params->is_ready)
        continue ;

    while (!p->simulation_params->is_over)
    {
        i = -1;
        while (++i < p->simulation_params->philosophers_count)
        {
            if (check_death(&p[i]))
                p->simulation_params->is_over = 1;
        }
        if (p->simulation_params->eaten_count == p->simulation_params->philosophers_count)
            p->simulation_params->is_over = 1;
    }

    return ;
}



void free_simulation(t_simulation *simulation)
{
    int i;

    if (!simulation)
        return;

    if (simulation->forks)
    {
        for (i = 0; i < simulation->philosophers_count; i++)
        {
            pthread_mutex_destroy(&simulation->forks[i]);
        }
        free(simulation->forks);
    }
    if (simulation->print_lock)
    {
        pthread_mutex_destroy(simulation->print_lock);
        free(simulation->print_lock);
    }
    free(simulation);
}
