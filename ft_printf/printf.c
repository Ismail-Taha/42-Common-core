/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:26:23 by isallali          #+#    #+#             */
/*   Updated: 2024/12/06 16:29:50 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	t_format	printers[9];
	int			count;
	va_list		args;

	if (!format)
		return (-1);
	count = 0;
	printers[0] = (t_format){'c', ft_putchar};
	printers[1] = (t_format){'s', ft_putstr};
	printers[2] = (t_format){'p', ft_putptr};
	printers[3] = (t_format){'d', ft_putnbr};
	printers[4] = (t_format){'i', ft_putnbr};
	printers[5] = (t_format){'u', ft_putnbr_unsg};
	printers[6] = (t_format){'x', ft_puthex};
	printers[7] = (t_format){'X', ft_puthexxa};
	printers[8] = (t_format){'\0', NULL};
	va_start(args, format);
	count = process(format, printers, args, &count);
	va_end(args);
	return (count);
}
