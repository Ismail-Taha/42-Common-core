/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:36:39 by isallali          #+#    #+#             */
/*   Updated: 2024/12/19 21:34:37 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	c_process(char *av, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error("Pipe creation failed", 1);
	pid = fork();
	if (pid == -1)
		error("Fork failed", 1);
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
		handle_exit_status(pid);
	}
}

void	heredoc(char *lm, int argc)
{
	pid_t	reader;
	int		fd[2];
	char	*ln;

	if (argc < 6)
		err_usage();
	if (pipe(fd) == -1)
		error("Pipe creation failed", 1);
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (get_next_line(&ln))
		{
			if (((s_l(ln) - 1) == s_l(lm)) && ft_strncmp(ln, lm, s_l(lm)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], ln, ft_strlen(ln));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		handle_exit_status(reader);
	}
}

void	last_process(char *av, char **envp, int fileout)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error("Fork failed for last process", EXIT_FAILURE);
	if (pid == 0)
	{
		dup2(fileout, STDOUT_FILENO);
		execution(av, envp);
	}
	else
	{
		handle_exit_status(pid);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	filein;
	int	fileout;

	if (argc < 5)
		err_usage();
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i = 3;
		fileout = open_f(argv[argc - 1], 0);
		heredoc(argv[2], argc);
	}
	else
	{
		i = 2;
		fileout = open_f(argv[argc - 1], 1);
		filein = open_f(argv[1], 2);
		dup2(filein, STDIN_FILENO);
	}
	while (i < argc - 2)
		c_process(argv[i++], envp);
	last_process(argv[argc - 2], envp, fileout);
}
