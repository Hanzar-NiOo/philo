/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 23:41:56 by hnioo             #+#    #+#             */
/*   Updated: 2026/02/15 00:55:13 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_thread(t_philo *philo)
{
	int	idx;

	idx = 0;
	while (idx < philo->number_of_philo)
	{
		pthread_create(&philo[idx].thread, NULL, &check_philo, &philo[idx]);
		idx++;
		usleep(100);
	}
	if (check_dead(philo))
		return ;
	idx = 0;
	while (idx < philo->number_of_philo)
	{
		pthread_join(philo[idx].thread, NULL);
		idx++;
	}
}

int	check_dead(t_philo *philo)
{
	if (philo->total_eaten == philo->must_eat)
		return (1);
	pthread_mutex_lock(philo->death);
	if (*philo->check_dead)
	{
		pthread_mutex_unlock(philo->death);
		return (1);
	}
	pthread_mutex_unlock(philo->death);
	if (ft_get_time() - philo->last_meal > philo->time_to_die)
	{
		print_for_philo(*philo, "DIE", 1);
		return (1);
	}
	return (0);
}

void	*check_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->number_of_philo == 1 && check_dead(philo))
	{
		if (pthread_mutex_lock(philo->left_fork))
			return (NULL);
		print_philo(philo, " took fork", 0);
		while (!check_dead(philo))
		{
		}
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		while (1)
		{
			if (check_dead(philo))
				break ;
			philo_eat(philo);
			philo_sleep(philo);
			philo_think(philo);
		}
	}
}
