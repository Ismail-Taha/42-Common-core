/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:04:46 by isallali          #+#    #+#             */
/*   Updated: 2024/10/22 14:05:35 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len > 0)
	{
		((char *)b)[len -1] = c;
		len--;
	}
	return (b);
}

/**
int main()
{
	int ptr[] = {1, 2, 3};
	int i = 0;
	int *ptr2 = (int *)ft_memset(ptr, 2, 4);
	while (i < 3)
	{
		printf("%d\n", ptr[i]);
		i++;
	}

}
*/