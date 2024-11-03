/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:58:18 by isallali          #+#    #+#             */
/*   Updated: 2024/10/22 21:34:23 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	len;

	if ((!dst && !src) || n == 0 || dst == src)
		return (dst);
	len = 0;
	if (src < dst)
	{
		len = n;
		while (len > 0)
		{
			len--;
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		while (len < n)
		{
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
			len++;
		}
	}
	return (dst);
}
