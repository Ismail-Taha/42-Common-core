/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:40:33 by isallali          #+#    #+#             */
/*   Updated: 2024/11/05 15:40:33 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		if (n == 0)
			return (1);
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	fill_str(char *str, long nb, size_t i)
{
	str[i] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return ;
	}
	while (nb > 0)
	{
		str[--i] = '0' + (nb % 10);
		nb /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	long	nb;

	nb = n;
	i = n_len(nb);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
		fill_str(str + 1, nb, i - 1);
	}
	else
		fill_str(str, nb, i);
	return (str);
}
