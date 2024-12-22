/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:05:58 by moleksan          #+#    #+#             */
/*   Updated: 2024/12/22 18:23:26 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H 

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h> 
# include <unistd.h>
# include <time.h>
# include <sys/time.h>
# include <stdint.h>

# define RESET		"\033[0m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define PURPLE		"\033[0;34m"
# define PINK		"\033[0;35m"
# define BLUE		"\033[0;36m"

typedef struct s_simulation_data
{
	int					is_ready;
	int					eating_time;
	int					dying_time;
	int					sleeping_time;
	int					eating_count;
	int					is_over;
	int					philosophers_count;
	int					has_check_sum;
	int					eaten_count;
	pthread_mutex_t		*print_lock;
	pthread_mutex_t		*forks;
}					t_simulation;

typedef struct s_philosopher
{
	int					philosopher_id;
	int					meal_count;
	long int			start_time;
	long int			last_meal_time;
	pthread_t			thread_id;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_simulation		*simulation_params;
}				t_philosopher;

//ch_input.c
int		ft_isdigit(int c);
int		is_positive_integer(const char *str);
int		ft_atoi(const char *str);
void	print_input_error(void);
int		validate_argument(const char *arg);
int		check_input(int ac, char **av);
void	prep_philosopher(t_philosopher *philo, t_simulation *sim, int id);

t_philosopher	*allocate_philosophers(t_simulation *simulation);
uint64_t		current_time(void);
t_simulation	*init_sim_data(char **argv);
t_philosopher	*init_philosophers(t_simulation *simulation);

void	free_simulation(t_simulation *simulation);

void	run_threads(t_philosopher *philosophers, t_simulation *simulation);
void	join_threads(t_philosopher *philosophers);
void	create_threads(t_philosopher *philosophers);

void	ft_usleep(long int time);
void	output_status(t_philosopher *p, int i);
void	cleanup_sim(t_philosopher *p);

void	*routine(void *phil);
void	philo_eat(t_philosopher *p);
int		check_death(t_philosopher *p);	
void	check_threads(t_philosopher *p);

#endif