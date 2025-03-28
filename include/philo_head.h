#ifndef PHIL_H
# define PHIL_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <stdint.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdint.h>

#define BACKGROUND_CYAN   "\033[48;5;6m"
#define BACKGROUND_RED    "\033[48;5;1m"
#define BACKGROUND_GREEN    "\033[48;5;2m"
#define RED          "\033[38;5;1m"
#define SAD_FACE         "\U0001F622"
#define RESET "\033[0m"

typedef struct s_simulation
{
    pthread_mutex_t *log_mutex;  
    pthread_mutex_t *forks;   
    int             sim_ready; 
    int             time_tdie;      
    int             time_tsleep;    
    int             time_teat;      
    int             meals_reqrd;   
    int             sim_end;   
    int             ttl_philo;    
    int             all_full;         
    int             meals_eaten;      
}               t_sim;


typedef struct s_individual
{
    pthread_t       thread_id;   
    pthread_mutex_t *lt_fork;     
    pthread_mutex_t *rt_fork;    
    int             philo_id;      
    int             times_eaten;    
    long int        start_time;     
    long int        last_meal;     
    t_sim    *shared_data;   
}               t_indv;

// validation_args
int args_valid(int ac, char **av);
int is_num(char *av);
int	ft_atoi(const char *str);
void err_msg(void);

// init
t_indv *init_data_philo(char **av, t_sim **data);
t_sim *init_sim(char **av);
t_sim *calloc_sim(int ttl_philo);


void philo_in(t_indv *p, t_sim *param);
void singl_philo_init(t_indv *ph_arr, int id, t_sim *param);


void debug_info(t_sim *sim, t_indv *philos);
void print_simulation_info(t_sim *sim, FILE *file);
void print_philosopher_info(t_indv *philo, FILE *file);

//tools
void ft_my_sleep(uint64_t duration);

#endif