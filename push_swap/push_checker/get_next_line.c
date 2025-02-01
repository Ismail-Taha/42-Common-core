/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:22:03 by isallali          #+#    #+#             */
/*   Updated: 2024/11/11 16:59:56 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	f_free(char *rbuffer)
{
	if (!rbuffer)
		return ;
	free(rbuffer);
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
	fbuffer = f_calloc(f_strlen(buffer) - i + 1, 1);
	if (!fbuffer)
		return (free(buffer), NULL);
	while (buffer[i])
		fbuffer[j++] = buffer[i++];
	fbuffer[j] = '\0';
	free(buffer);
	return (fbuffer);
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
		line = f_calloc(i + 2, 1);
	else
		line = f_calloc(i + 1, 1);
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

char	*ft_readf(int fd, char *nbuffer)
{
	char	*buffer;
	int		r;

	r = 1;
	buffer = f_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r < 0)
			return (f_free(buffer), f_free(nbuffer), NULL);
		if (!r)
			break ;
		buffer[r] = 0;
		nbuffer = f_strjoin(nbuffer, buffer);
		if (!nbuffer)
			return (f_free(buffer), NULL);
		if (f_strchr(nbuffer, '\n'))
			break ;
	}
	f_free(buffer);
	return (nbuffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	buffer = ft_readf(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = next_line(buffer);
	return (line);
}
