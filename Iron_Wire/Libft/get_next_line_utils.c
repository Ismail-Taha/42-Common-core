/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:21:55 by isallali          #+#    #+#             */
/*   Updated: 2025/02/07 12:52:13 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	f_strchr(char *s, char c)
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

size_t	f_strlen(char *s)
{
	while (*s != '\0')
		return (1 + f_strlen(s + 1));
	return (0);
}

void	*f_calloc(size_t count, size_t size)
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

char	*f_strdup(const char *s)
{
	int		len;
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	len = f_strlen((char *)s);
	str = f_calloc(sizeof(char) * (len + 1), 1);
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

char	*f_strjoin(char *s1, char *s2)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = f_strdup("");
	str = f_calloc(sizeof(char) * (f_strlen(s1) + f_strlen(s2) + 1), 1);
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
