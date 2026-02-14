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

typedef enum s_error
{
	ARG_COUNT,
	ARG_VALUE,
}	t_error;

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

int		error(t_error type);
void	find_error_type(t_error type);

void	check_arg(int argc, char **argv);
void	check_argc(int argc);
void	check_argv(int argc, char **argv);

#endif