/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:07:06 by isallali          #+#    #+#             */
/*   Updated: 2024/12/06 14:41:11 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putc(char c)
{
	return (write(1, &c, 1));
}

int	ft_putchar(va_list args, t_flags *flags)
{
	char	c;

	(void)flags;
	c = (char)va_arg(args, int);
	return (ft_putc(c));
}

int	ft_putstrr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	while (str[i] != '\0')
	{
		if (ft_putc(str[i++]) == -1)
			return (-1);
	}
	return (i);
}

int	ft_putstr(va_list args, t_flags *flags)
{
	char	*str;

	(void)flags;
	str = va_arg(args, char *);
	return (ft_putstrr(str));
}

char	*ft_strchr(char *s, int i)
{
	char	c;

	c = (char)i;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}
