/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:44:17 by isallali          #+#    #+#             */
/*   Updated: 2024/12/19 21:16:23 by isallali         ###   ########.fr       */
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

void c_fork_p(int *fd, char **av, char **envp, pid_t *c_pid, pid_t *c_pid2)
{
	if (pipe(fd) == -1)
		error("Failed to create pipe", EXIT_FAILURE);
	if ((*c_pid = fork()) == -1)
		error("Failed to fork process1", EXIT_FAILURE);
	if (*c_pid == 0)
		c_process(av, envp, fd);
	if ((*c_pid2 = fork()) == -1)
		error("Failed to fork process2", EXIT_FAILURE);
	if (*c_pid2 == 0)
		p_process(av, envp, fd);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	c_pid;
	pid_t	c_pid2;

	if (ac != 5)
	{
		ft_putstr_fd("Error: Invalid arguments\n", 2);
		ft_putstr_fd("Usage: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
		exit(EXIT_FAILURE);
	}
	if (av[3][0] == 0 || av[2][0] == 0)
		error("Command arguments are empty", EXIT_FAILURE);
	c_fork_p(fd, av, envp, &c_pid, &c_pid2);
	close(fd[0]);
	close(fd[1]);
	handle_exit_status(c_pid);
	handle_exit_status(c_pid2);
	return (0);
}
