/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:06:36 by isallali          #+#    #+#             */
/*   Updated: 2024/10/22 21:11:14 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	len1;
	unsigned int	len2;

	len1 = 0;
	len2 = 0;
	k = 0;
	while (dest[len1])
		len1++;
	while (src[len2])
		len2++;
	i = len1;
	while (src[k] && i < (size -1) && size != 0)
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	if (len1 > size)
		return (size + len2);
	return (len1 + len2);
}
