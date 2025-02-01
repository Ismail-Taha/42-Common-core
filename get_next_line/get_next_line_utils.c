/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:21:55 by isallali          #+#    #+#             */
/*   Updated: 2024/11/15 16:20:44 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

size_t	ft_strlen(char *s)
{
	while (*s != '\0')
		return (1 + ft_strlen(s + 1));
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*alloc;

	if (!count || !size)
		return (NULL);
	if (size != 0 && size > (SIZE_MAX / count))
		return (NULL);
	alloc = malloc(count * size);
	if (!alloc)
		return (NULL);
	return (alloc);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen((char *)s);
	str = ft_calloc(sizeof(char) * (len + 1), 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	str = ft_calloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1), 1);
	if (!str)
		return (free(s1), NULL);
	if (s1)
		while (s1[i])
			str[j++] = s1[i++];
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (free(s1), str);
}
