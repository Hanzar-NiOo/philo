/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 00:27:48 by hnioo             #+#    #+#             */
/*   Updated: 2026/02/15 03:05:58 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_time	get_time(void)
{
	struct timeval	tp;
	t_time			time;

	gettimeofday(&tp, NULL);
	time = tp.tv_sec * 1000 + (tp.tv_usec / 1000);
	return (time);
}

void	philo_init(int argc, char **argv, t_philo *philo)
{
	int	idx;
	int	*death;

	idx = 0;
	death = malloc(sizeof(int));
	if (!death)
		error(MALLOC);
	*death = 0;
	while (idx < ft_atoi(argv[1]))
	{
		philo[idx].id = idx;
		philo[idx].number_of_philo = ft_atoi(argv[1]);
		philo[idx].time_to_die = ft_atoi(argv[2]);
		philo[idx].time_to_eat = ft_atoi(argv[3]);
		philo[idx].time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			philo[idx].must_eat = ft_atoi(argv[5]);
		else
			philo[idx].must_eat = -1;
		philo[idx].total_eaten = 0;
		philo[idx].start_time = get_time();
		philo[idx].last_meal = get_time();
		philo[idx].check_dead = death;
		idx++;
	}
}

void	mutex_init(t_philo *philo, pthread_mutex_t	*forks,
		pthread_mutex_t	*death)
{
	int	idx;

	idx = 0;
	while (idx < philo->number_of_philo)
	{
		philo[idx].left_fork = &forks[idx];
		philo[idx].right_fork = &forks[(idx + 1) % philo->number_of_philo];
		idx++;
	}
	idx = 0;
	while (idx < philo->number_of_philo)
	{
		pthread_mutex_init(philo[idx].left_fork, NULL);
		pthread_mutex_init(philo[idx].right_fork, NULL);
		philo[idx].death = death;
		idx++;
	}
	pthread_mutex_init(philo->death, NULL);
}
