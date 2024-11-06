/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:38:48 by isallali          #+#    #+#             */
/*   Updated: 2024/11/05 15:38:48 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	len;
	void	*c;

	if (count != 0 && (18446744073709551615UL / count < size))
		return (NULL);
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	len = count * size;
	c = malloc(len);
	if (c == NULL)
		return (NULL);
	else
		ft_bzero(c, len);
	return (c);
}
