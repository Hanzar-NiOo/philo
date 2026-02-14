/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:12:59 by hnioo             #+#    #+#             */
/*   Updated: 2026/02/14 21:12:59 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(t_error type)
{
	write (2, "error\n", 6);
	find_error_type(type);
	exit(EXIT_FAILURE);
}

void	find_error_type(t_error type)
{
	if (type == ARG_COUNT)
		write(2, "Argument count must be 5 (or) 6\n", 32);
	else if (type == ARG_VALUE)
		write(2, "Argument values aren't valid\n", 30);
	else if (type == MALLOC)
		write(2, "Memory allocation fail\n", 30);
}
