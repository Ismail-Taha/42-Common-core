/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:33:59 by isallali          #+#    #+#             */
/*   Updated: 2024/12/19 22:21:09 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "inclibft/libft.h"

typedef struct s_path_info
{
	char	**path;
	char	*ppath;
	char	*expath;
}	t_path_info;

void	error(char *msg, int status);
void	exit_status(pid_t child_pid);
char	*extract_path(char *cmd, char **envp);
void	execution(char *av, char **envp);
int		get_next_line(char **line);
int		open_f(char *argv, int i);
void	err_usage(void);
size_t	s_l(const char *s);

#endif /*PIPEX_H*/
