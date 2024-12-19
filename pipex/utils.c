/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:42:43 by isallali          #+#    #+#             */
/*   Updated: 2024/12/19 21:16:40 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*extract_path(char *cmd, char **envp)
{
	t_path_info	info;
	int			i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	if (envp[i] == NULL)
		return (0);
	info.path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (info.path && info.path[i])
	{
		info.ppath = ft_strjoin(info.path[i], "/");
		info.expath = ft_strjoin(info.ppath, cmd);
		free(info.ppath);
		if (access(info.expath, F_OK) == 0)
			return (info.expath);
		free(info.expath);
		i++;
	}
	i = -1;
	while (info.path && info.path[++i])
		free(info.path[i]);
	free(info.path);
	return (0);
}

void	execution(char *av, char **envp)
{
	char	**cmd;
	int		i;
	char	*expath;

	i = -1;
	cmd = ft_split(av, ' ');
	if (!cmd)
		error("Failed to parse command", 2);
	if (ft_strchr(cmd[0], '/'))
		expath = cmd[0];
	else
		expath = extract_path(cmd[0], envp);
	if (!expath || access(expath, X_OK) == -1)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error("Command not found or not executable", 127);
	}
	if (execve(expath, cmd, envp) == -1)
		error("Execve failed", 126);
}

void	error(char *msg, int status)
{
	if (msg)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}
	else
		perror("Error");
	exit(status);
}

void handle_exit_status(pid_t child_pid)
{
	int exit_code;
	int signal_number;
    int status;

    if (waitpid(child_pid, &status, 0) == -1)
        error("Failed to wait for child process", EXIT_FAILURE);
    if (WIFEXITED(status))
	{
		exit_code = WEXITSTATUS(status);
        if (exit_code != 0)
            error("Child process exited with error", exit_code);
    }
	else if (WIFSIGNALED(status))
	{
		signal_number = WTERMSIG(status);
        error("Child process terminated by signal", signal_number);
    }
}
