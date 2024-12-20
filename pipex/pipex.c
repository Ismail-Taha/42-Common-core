/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:44:17 by isallali          #+#    #+#             */
/*   Updated: 2024/12/20 20:54:30 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	c_process(char **av, char **envp, int *fd)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		error("Cannot open input file", EXIT_FAILURE);
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(infile);
	execution(av[2], envp);
}

void	p_process(char **av, char **envp, int *fd)
{
	int	outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		error("Cannot open or create output file", EXIT_FAILURE);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(outfile);
	execution(av[3], envp);
}

void	c_fork_p(t_pipex *pipex)
{
	if (pipe(pipex->fd) == -1)
		error("Failed to create pipe", EXIT_FAILURE);
	pipex->c_pid1 = fork();
	if (pipex->c_pid1 == -1)
		error("Failed to fork process1", EXIT_FAILURE);
	if (pipex->c_pid1 == 0)
		c_process(pipex->argv, pipex->envp, pipex->fd);
	pipex->c_pid2 = fork();
	if (pipex->c_pid2 == -1)
		error("Failed to fork process2", EXIT_FAILURE);
	if (pipex->c_pid2 == 0)
		p_process(pipex->argv, pipex->envp, pipex->fd);
}

void	init_data(t_pipex *pipex, char **av, char **envp)
{
	pipex->argv = av;
	pipex->envp = envp;
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac != 5)
	{
		ft_putstr_fd("Error: Invalid arguments\n", 2);
		ft_putstr_fd("Usage: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
		exit(EXIT_FAILURE);
	}
	if (av[3][0] == 0 || av[2][0] == 0)
		error("Command arguments are empty", EXIT_FAILURE);
	init_data(&pipex, av, envp);
	c_fork_p(&pipex);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	exit_status(pipex.c_pid1);
	return (exit_status(pipex.c_pid2));
}
