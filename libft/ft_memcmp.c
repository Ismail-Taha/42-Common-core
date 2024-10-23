/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:54:39 by isallali          #+#    #+#             */
/*   Updated: 2024/10/23 13:05:29 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*scp1;
	char	*scp2;
	size_t	i;

	scp1 = (char *)s1;
	scp2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (scp1[i] != scp2[i])
			return ((unsigned char)scp1[i] - (unsigned char)scp2[i]);
		i++;
	}
	return (0);
}
