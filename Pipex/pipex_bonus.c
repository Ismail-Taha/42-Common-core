#include "pipex.h"

void	c_process(char *av, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execution(av, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	i;
	int	filein;
	int	fileout;

	if (ac >= 5)
	{
		i = 2;
		fileout = open_f(av[ac - 1], 1);
		filein = open_f(av[1], 2);
		dup2(filein, STDIN_FILENO);
		while (i < ac - 2)
			c_process(av[i++], envp);
		dup2(fileout, STDOUT_FILENO);
		execution(av[ac - 2], envp);
	}
	err_usage();
}
