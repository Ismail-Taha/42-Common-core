/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:07:16 by isallali          #+#    #+#             */
/*   Updated: 2024/12/05 22:36:04 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putptr(va_list args, t_flags *flags)
{
	unsigned long	num;
	char			buffer[17];
	int				i;
	int				count;

	count = 0;
	num = (unsigned long)va_arg(args, void *);
	buffer[16] = '\0';
	i = 15;
	if (num == 0)
		return (ft_putstrr("(nil)"));
	if (flags->space && flags->plus)
		count += ft_putc('+');
	else if (flags->space)
		count += ft_putc(' ');
	else if (flags->plus)
		count += ft_putc('+');
	while (num > 0)
	{
		buffer[i--] = base_to_char(num % 16, 'x');
		num /= 16;
	}
	count += ft_putstrr("0x") + ft_putstrr(buffer + i + 1);
	return (count);
}
