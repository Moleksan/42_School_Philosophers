#include "philosophers.h"

void print_error(char *error_message)
{
    printf("%s", error_message);
}

int init_sim(t_simulation **sim, char **av)
{
   if(!(*sim = (t_simulation *)malloc(sizeof(t_simulation))))
   {
        print_error("Error: Memory allocation failed for simulation.\n");
        return (0);
   }

    (*sim)->num_philos = ft_atoi(av[1]);
    (*sim)->time_to_die = ft_atoi(av[2]);
    (*sim)->time_to_eat = ft_atoi(av[3]);
    (*sim)->time_to_sleep = ft_atoi(av[4]);
    if(av[5])
    {
        (*sim)->meals_required = ft_atoi(av[5]);
    }
    else
    {
        (*sim)->meals_required = -1;
    }
    print_error("init ok");
    return (1);
}


int main(int ac, char **av)
{
    t_simulation *sim;

    if(!check_input(ac, av))
        return (0);
    if(!init_sim(&sim, av))
        return (0);
    
}