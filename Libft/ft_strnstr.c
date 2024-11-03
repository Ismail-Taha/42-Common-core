/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:12:41 by isallali          #+#    #+#             */
/*   Updated: 2024/10/23 20:48:47 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *target, size_t n)
{
	size_t	targ_len;

	targ_len = ft_strlen(target);
	if (!str && n == 0)
		return (NULL);
	if (targ_len == 0)
		return ((char *)str);
	while (*str && n >= targ_len)
	{
		if (ft_strncmp(str, target, targ_len) == 0)
			return ((char *)str);
		str++;
		n--;
	}
	return (NULL);
}