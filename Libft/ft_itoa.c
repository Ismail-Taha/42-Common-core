/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 01:58:23 by isallali          #+#    #+#             */
/*   Updated: 2024/10/25 02:09:59 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int n_len(long n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void fill_str(char *str, long nb, size_t i)
{

	if (nb == 0)
	{
		str[0] = '0';
		return;
	}
	while (nb > 0)
	{
        str[i--] = '0' + (nb % 10);
        nb /= 10;
    }
}
char	*ft_itoa(int n)
{
	char *str;
	int i;
	long nb;

	i = 0;
	nb = n;
	str = malloc(sizeof(char) * (n_len(nb) + 1));
	if (!str)
		return (NULL);
	i = n_len(nb);
	str[i--] = 0;
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
