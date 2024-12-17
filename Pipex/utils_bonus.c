#include "pipex.h"
#include "libft.h"

void	err_usage(void)
{
	ft_putstr_fd("\033[31mError: Bad argument\n\e[0m", 2);
	ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
	ft_putstr_fd("    ./pipex \"here_doc\" <LIMITER> <cmd> <cmd1> <...> <file>\n", 1);
	exit(EXIT_SUCCESS);
}

int	open_f(char *argv, int option)
{
	int	file;

	file = 0;
	if (option == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (option == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (option == 2)
		file = open(argv, O_RDONLY);
	if (file == -1)
		error();
	return (file);
}
