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


/* Структура для хранения всех параметров симуляции */
typedef struct s_simulation
{
    pthread_mutex_t *log_mutex;        // Мьютекс для вывода
    pthread_mutex_t *forks;            // Массив мьютексов для вилок
    int             sim_ready;  // Индикатор готовности симуляции
    int             time_tdie;       // Время до смерти философа без еды
    int             time_tsleep;     // Время сна
    int             time_teat;       // Время, которое требуется на еду
    int             meals_reqrd;    // Необходимое количество приёмов пищи
    int             sim_end;    // Флаг окончания симуляции
    int             ttl_philo;      // Общее количество философов
    int             all_full;          // Флаг, указывающий, что все философы наелись
    int             meals_eaten;       // Счётчик съеденных приемов пищи
}               t_sim;

/* Структура для представления каждого философа */
typedef struct s_individual
{
    pthread_t       thread_id;      // Поток, связанный с философом
    pthread_mutex_t *lt_fork;     // Ссылка на левую вилку
    pthread_mutex_t *rt_fork;    // Ссылка на правую вилку
    int             philo_id;       // Уникальный идентификатор философа
    int             times_eaten;    // Количество приемов пищи
    long int        start_time;     // Начальное время симуляции
    long int        last_meal;      // Время последнего приема пищи
    t_sim    *shared_data;   // Указатель на общую структуру симуляции
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