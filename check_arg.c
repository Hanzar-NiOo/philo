#include "philo.h"

void	check_arg(int argc, char **argv)
{
	check_argc(argc);
	check_argv(argc, argv);
}

void	check_argc(int argc)
{
	if (argc != 5 && argc != 6)
		error (ARG_COUNT);
}

void	check_argv(int argc, char **argv)
{
	int	arg_idx;
	int	char_idx;

	arg_idx = 1;
	while (arg_idx != argc)
	{
		char_idx = 0;
		while (argv[arg_idx][char_idx])
		{
			if (argv[arg_idx][0] == '0')
				error (ARG_VALUE);
			if (argv[arg_idx][char_idx] < 48 || argv[arg_idx][char_idx] > 58)
				error (ARG_VALUE);
			char_idx++;
		}
		arg_idx++;
	}
}
