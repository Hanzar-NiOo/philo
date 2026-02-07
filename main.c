#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		error ();
	else
		printf("%s\n", argv [0]);
	return (0);
}
