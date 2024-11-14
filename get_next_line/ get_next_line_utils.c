/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:21:55 by isallali          #+#    #+#             */
/*   Updated: 2024/11/11 16:59:59 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int i)
{
	char	c;

	c = (char)i;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	while (*s != '\0')
		return (1 + ft_strlen(s + 1));
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*alloc;
	size_t	i;

	i = 0;
	if (!count || !size)
		return (NULL);
	if (size != 0 && size > (SIZE_MAX / count))
		return (NULL);
	alloc = malloc(count * size);
	if (!alloc)
		return (NULL);
	return (alloc);
}


void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*ssrc;

	if (!dst && !src)
		return (dst);
	dest = (char *)dst;
	ssrc = (char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = ssrc[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (0);
	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	if (s2)
		len2 = ft_strlen(s2);
	else
		len2 = 0;
	str = ft_calloc((len1 + len2 + 1), sizeof(char));
	if (!str)
		return (0);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2);
	return (str);
}
