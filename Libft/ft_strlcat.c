/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:47:32 by isallali          #+#    #+#             */
/*   Updated: 2024/11/05 15:47:32 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	k;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	k = 0;
	if (!dest && !size)
		return (ft_strlen(src));
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
	if (len1 >= size)
		return (size + len2);
	return (len1 + len2);
}
