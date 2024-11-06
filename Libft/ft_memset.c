/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:45:25 by isallali          #+#    #+#             */
/*   Updated: 2024/11/05 15:45:25 by isallali         ###   ########.fr       */
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

/**#include <stdio.h>
int main()
{
	int a;
	int b;
	int c;

	ft_memset(&a,232, 1);
	ft_memset((void *)&a + 1, 3, 1);
	ft_memset((void *)&a + 2, 0, 2);
	printf("%d\n", a);

	ft_bzero(&b, 4);
	ft_memset(&b, 57, 1);
	ft_memset((void *)&b + 1, 5, 1);
	printf("%d\n", b);

	ft_memset(&c,24, 1);
	ft_memset((void *)&c + 1, 252, 1);
	ft_memset((void *)&c + 2, 255, 2);
	printf("%d\n", c);

}*/
