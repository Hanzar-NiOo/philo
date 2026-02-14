/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:27:13 by hnioo             #+#    #+#             */
/*   Updated: 2026/02/15 00:48:47 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

void	print_for_philo(t_philo *philo, char *str, int status)
{
	pthread_mutex_lock(philo->death);
	if (!*philo->check_dead)
	{
		printf("%llu %d %s\n", (ft_get_time() - philo->start_time),
			philo->id + 1, status);
		if (status)
			*philo->check_dead = 1;
	}
	pthread_mutex_unlock(philo->death);
	check_dead(philo);
}
