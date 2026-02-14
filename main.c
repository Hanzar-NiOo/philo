/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:12:45 by hnioo             #+#    #+#             */
/*   Updated: 2026/02/14 21:12:45 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;

	check_arg(argc, argv);
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	death = malloc(sizeof(pthread_mutex_t));
	if (!philo || !forks || !death)
		error(MALLOC);
	philo_init(argc, argv, philo);
	mutex_init(philo, forks, death);
	return (0);
}
