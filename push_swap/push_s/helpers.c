/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:57:48 by isallali          #+#    #+#             */
/*   Updated: 2025/02/05 15:35:53 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		free(str[i]);
	free(str);
}

void	pr_err(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	cmp_value(int a, int b)
{
	return (a == b);
}

int	split_size(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_overflow(long res, int sign, char digit)
{
	if (sign == 1)
		return (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit
				- 48 > INT_MAX % 10));
	else
		return (res > -(INT_MIN / 10) || (res == -(INT_MIN / 10) && digit
				- 48 > -(INT_MIN % 10)));
}
