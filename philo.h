/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:13:34 by hnioo             #+#    #+#             */
/*   Updated: 2026/02/14 21:13:34 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef enum s_error
{
	ARG_COUNT,
	ARG_VALUE,
	MALLOC,
}	t_error;

typedef unsigned long long	t_time;

typedef struct s_philo
{
	int				id;
	int				must_eat;
	int				number_of_philo;
	int				total_eaten;
	int				*check_dead;
	t_time			time_to_die;
	t_time			time_to_eat;
	t_time			time_to_sleep;
	t_time			start_time;
	t_time			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*death;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

int		error(t_error type);
void	find_error_type(t_error type);

void	check_arg(int argc, char **argv);
void	check_argc(int argc);
void	check_argv(int argc, char **argv);
void	philo_init(int argc, char **argv, t_philo *philo);
void	mutex_init(t_philo *philo, pthread_mutex_t *forks, pthread_mutex_t *death);
void	*check_philo(void *arg);
t_time	get_time(void);
long	ft_atoi(const char *str);
void	print_philo(t_philo *philo, char *str, int status);
int		check_dead(t_philo *philo);

#endif