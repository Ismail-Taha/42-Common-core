/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:49:17 by isallali          #+#    #+#             */
/*   Updated: 2024/11/05 15:49:17 by isallali         ###   ########.fr       */
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
