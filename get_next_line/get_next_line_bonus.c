/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:51:17 by isallali          #+#    #+#             */
/*   Updated: 2024/11/15 12:33:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(char *readed)
{
	if (!readed)
		return ;
	free(readed);
}

char	*read_file(int fd, char *readed)
{
	char	*buffer;
	int		r;

	r = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r < 0)
			return (ft_free(buffer), ft_free(readed), NULL);
		if (!r)
			break ;
		buffer[r] = 0;
		readed = ft_strjoin(readed, buffer);
		if (!readed)
			return (ft_free(buffer), NULL);
		if (ft_strchr(readed, '\n'))
			break ;
	}
	ft_free(buffer);
	return (readed);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_calloc(i + 2, 1);
	else
		line = ft_calloc(i + 1, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_get_next_line(char *buffer)
{
	char	*nbuffer;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	i++;
	nbuffer = ft_calloc(ft_strlen(buffer) - i + 1, 1);
	if (!nbuffer)
		return (free(buffer), NULL);
	while (buffer[i])
		nbuffer[j++] = buffer[i++];
	nbuffer[j] = '\0';
	free(buffer);
	return (nbuffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD || BUFFER_SIZE >= 2147483647)
		return (NULL);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = get_line(buffer[fd]);
	buffer[fd] = ft_get_next_line(buffer[fd]);
	return (line);
}