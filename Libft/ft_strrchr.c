/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:25:49 by isallali          #+#    #+#             */
/*   Updated: 2024/10/23 12:32:54 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char *)s + 1);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)s + 1);
		i--;
	}
	return (NULL);
}
