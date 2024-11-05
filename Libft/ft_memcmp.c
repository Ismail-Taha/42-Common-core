/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:43:42 by isallali          #+#    #+#             */
/*   Updated: 2024/11/05 15:43:42 by isallali         ###   ########.fr       */
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
