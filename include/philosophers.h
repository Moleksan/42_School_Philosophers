#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H 

#include <stdio.h>
#include <stdlib.h>

typedef struct s_simulation
{
    int                 num_philos;        
    int                 time_to_die;       
    int                 time_to_eat;       
    int                 time_to_sleep;    
    int                 meals_required;          
}               t_simulation;


int check_input(int ac, char **av);
int	ft_atoi(const char *str);
int is_positive_integer(const char *str);
int ft_isdigit(int c);

#endif