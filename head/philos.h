/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:29:00 by moleksan          #+#    #+#             */
/*   Updated: 2025/04/07 00:42:06 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <stdint.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_philosopher
{
	pthread_t		thread;
	int				id;
	int				is_eating;
	int				meals_eaten;
	size_t			last_meal_time;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				total_philos;
	int				required_meals;
	int				*simulation_end;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*log_mutex;
	pthread_mutex_t	*death_mutex;
	pthread_mutex_t	*meal_mutex;
}					t_info;
typedef struct s_simulation
{
	int				sim_end;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	log_mutex;
	pthread_mutex_t	*forks;
	pthread_t		check;
	t_info			*philos;
}					t_sim;

//valid
int		ft_atoi(const char *str);
int		is_num(char *av);
int		args_valid(int ac, char **av);
int		ft_strcmp(const char *str1, const char *str2);

//threads
int		threads_start(t_sim *simulation);
void	*control(void *args);
int		if_ate(t_info *philos);
int		philosopher_dead(t_info *philo, size_t time_to_die);
int		if_dead(t_info *philos);
//routine
void	take_forks_and_eat(t_info *philo);
void	rest_and_think(t_info *philo);
void	*routine(void *args);
int		threads_wait(t_sim *sim);
//init
int		init_sim_param(t_sim *program, int num_of_philos, char **av);
void	init_philo_info(t_info *philos, char **argv);
void	init_mutx_frk(t_info *philos, t_sim *simulation,
			pthread_mutex_t *forks, int total_philos);
//tools
void	print_action(t_info *philo, const char *action);
size_t	get_time(void);
int		ft_usleep(size_t milliseconds);
void	destroy_all(t_sim *program, pthread_mutex_t *forks);

#endif
