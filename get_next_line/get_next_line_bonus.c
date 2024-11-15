/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:51:17 by isallali          #+#    #+#             */
/*   Updated: 2024/11/15 15:17:29 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(char *rbuffer)
{
	if (!rbuffer)
		return ;
	free(rbuffer);
}

char	*ft_readf(int fd, char *nbuffer)
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
			return (ft_free(buffer), ft_free(nbuffer), NULL);
		if (!r)
			break ;
		buffer[r] = 0;
		nbuffer = ft_strjoin(nbuffer, buffer);
		if (!nbuffer)
			return (ft_free(buffer), NULL);
		if (ft_strchr(nbuffer, '\n'))
			break ;
	}
	ft_free(buffer);
	return (nbuffer);
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

char	*next_line(char *buffer)
{
	char	*fbuffer;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	i++;
	fbuffer = ft_calloc(ft_strlen(buffer) - i + 1, 1);
	if (!fbuffer)
		return (free(buffer), NULL);
	while (buffer[i])
		fbuffer[j++] = buffer[i++];
	fbuffer[j] = '\0';
	free(buffer);
	return (fbuffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD || BUFFER_SIZE >= 2147483647)
		return (NULL);
	buffer[fd] = ft_readf(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = get_line(buffer[fd]);
	buffer[fd] = next_line(buffer[fd]);
	return (line);
}
