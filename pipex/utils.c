/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:42:43 by isallali          #+#    #+#             */
/*   Updated: 2024/12/20 20:59:15 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_executable(char **path, char *cmd)
{
	char	*ppath;
	char	*expath;
	int		i;

	i = 0;
	while (path && path[i])
	{
		ppath = ft_strjoin(path[i], "/");
		expath = ft_strjoin(ppath, cmd);
		free(ppath);
		if (access(expath, F_OK) == 0)
		{
			free_path_array(path);
			return (expath);
		}
		free(expath);
		i++;
	}
	free_path_array(path);
	return (NULL);
}

char	*extract_path(char *cmd, char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	if (envp[i] == NULL)
		return (NULL);
	path = ft_split(envp[i] + 5, ':');
	return (find_executable(path, cmd));
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
		if (expath)
			free(expath);
		error("Command not found or not executable", 127);
	}
	execve(expath, cmd, envp);
	perror("Error");
	exit(126);
}

int	exit_status(pid_t child_pid)
{
	int	status;
	int	exit_status;

	exit_status = 0;
	if (waitpid(child_pid, &status, 0) == -1)
		error("Failed to wait for child process", EXIT_FAILURE);
	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
	return (exit_status);
}

void	error(char *msg, int status)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(status);
}
