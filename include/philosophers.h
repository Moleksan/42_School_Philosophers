#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 

typedef struct s_simulation
{
    int                 num_philos;        
    int                 time_to_die;       
    int                 time_to_eat;       
    int                 time_to_sleep;    
    int                 meals_required;    
    pthread_mutex_t     *forks;  
}               t_simulation;

typedef struct s_philosopher
{
    int             id;
    int             meal_eaten;
    long int        last_meal_time;
    pthread_t       thread_id;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;             
    t_simulation     *sim_params; 
}               t_philosopher;


int check_input(int ac, char **av);
int	ft_atoi(const char *str);
int is_positive_integer(const char *str);
int ft_isdigit(int c);

#endif