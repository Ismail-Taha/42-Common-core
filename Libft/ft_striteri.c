/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:38:39 by isallali          #+#    #+#             */
/*   Updated: 2024/11/05 14:05:28 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
/**#include <stdio.h>
void zbi(unsigned int i, char *c)
{
	*c = ft_toupper(*c);
}
int main()
{
	char str[] = "joeisvalidated";
	ft_striteri(str, zbi);
	printf("%s\n", str);
}*/
