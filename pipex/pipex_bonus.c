/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:36:39 by isallali          #+#    #+#             */
/*   Updated: 2025/01/20 17:25:00 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	c_process(t_pipex *px, char *av)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error("Pipe creation failed", 1);
	pid = fork();
	if (pid == -1)
	{
		free(px->pids);
		error("Fork failed", 1);
	}
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execution(av, px->envp, px);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	px->pids[px->index] = pid;
}

void	last_process(t_pipex *px, char *av)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		free(px->pids);
		error("Fork failed", 1);
	}
	if (pid == 0)
	{
		px->fileout = open_f(px->argv[px->argc - 1], 1, px);
		dup2(px->fileout, STDOUT_FILENO);
		close(px->fileout);
		execution(av, px->envp, px);
	}
	px->pids[px->index] = pid;
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
		exit_status(reader);
	}
}

void	handle_input(t_pipex *px)
{
	if (ft_strncmp(px->argv[1], "here_doc", 8) == 0)
	{
		px->i = 3;
		px->fileout = open_f(px->argv[px->argc - 1], 0, px);
		heredoc(px->argv[2], px->argc);
	}
	else
	{
		px->i = 2;
		px->filein = open_f(px->argv[1], 2, px);
		dup2(px->filein, STDIN_FILENO);
		close(px->filein);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;
	int		exit;

	exit = 0;
	if (argc < 5)
		err_usage();
	init_pipex(&px, argc, argv, envp);
	handle_input(&px);
	while (px.i < argc - 2)
	{
		c_process(&px, argv[px.i]);
		px.i++;
		px.index++;
	}
	last_process(&px, argv[argc - 2]);
	px.i = 0;
	while (px.i <= px.index)
		exit = exit_status(px.pids[px.i++]);
	free(px.pids);
	return (exit);
}
