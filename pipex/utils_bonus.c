/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:53:12 by isallali          #+#    #+#             */
/*   Updated: 2024/12/17 22:53:13 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	err_usage(void)
{
	ft_putstr_fd("Error: Bad argument\n", 2);
	ft_putstr_fd("Usage:\n", 1);
	ft_putstr_fd("  ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
	ft_putstr_fd("  ./pipex \"here_doc\" <LIMITER> <cmd> <cmd1> <...> <file>\n", 1);
	exit(EXIT_FAILURE);
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
		error("Failed to open file", 1);
	return (file);
}

int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		readed;
	char	core;

	i = 0;
	readed = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	readed = read(0, &core, 1);
	while (readed && core != '\n')
	{
		buffer[i] = core;
		i++;
		readed = read(0, &core, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (readed);
}
