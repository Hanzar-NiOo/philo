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
}
