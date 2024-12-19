#include "philosophers.h"

int main(int ac, char **av)
{
    t_simulation *sim = NULL;
    t_philosopher *philo = NULL;

    if(!(check_input(ac, av)))
    {
        return (0);
    }
    if(!(sim = init_sim_data(av)))
        return (0);
    if(!(philo = init_philosophers(sim)))
    {
        free_simulation(sim);
        return (1);
    }
    run_threads(philo, sim);
    join_threads(philo);
    cleanup_sim(philo);
    return (0);
}


