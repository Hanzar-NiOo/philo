/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:25:58 by hnioo             #+#    #+#             */
/*   Updated: 2026/02/15 02:50:25 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	if (check_dead(philo))
		return ;
	pthread_mutex_lock(philo->left_fork);
	print_philo(philo, " took fork\n", 0);
	pthread_mutex_lock(philo->right_fork);
	if (check_dead(philo))
		return ;
	print_philo(philo, " took fork\n", 0);
	pthread_mutex_lock(philo->death);
	philo->total_eaten++;
	pthread_mutex_unlock(philo->death);
	print_philo(philo, " is eating\n", 0);
	philo_wait(philo, philo->time_to_eat);
	pthread_mutex_lock(philo->death);
	philo->last_meal = get_time();
	pthread_mutex_unlock(philo->death);
	if (check_dead(philo))
		return ;
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (check_dead(philo))
		return ;
	print_philo(philo, " is sleeping\n", 0);
	philo_wait(philo, philo->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	if (check_dead(philo))
		return ;
	print_philo(philo, " is thinking\n", 0);
}
