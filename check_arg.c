#include "philo.h"

void	check_arg(int argc, char **argv)
{
	int	arg_idx;
	int	char_idx;

	if (argc != 5 && argc != 6)
		error ();
	arg_idx = 1;
	while (arg_idx != argc)
	{
		char_idx = 0;
		while (argv[arg_idx][char_idx])
		{
			if (argv[arg_idx][0] == '0')
				error ();
			if (argv[arg_idx][char_idx] < 48 || argv[arg_idx][char_idx] > 58)
				error ();
			char_idx++;
		}
		arg_idx++;
	}
}
