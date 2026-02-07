#include "philo.h"

int	error(void)
{
	write (2, "error\n", 6);
	exit(EXIT_FAILURE);
}
