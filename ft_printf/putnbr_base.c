/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:07:19 by isallali          #+#    #+#             */
/*   Updated: 2024/12/05 15:20:48 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	base_to_char(unsigned long num, char c)
{
	char	*hex_digits;

	hex_digits = NULL;
	if (c == 'x')
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	return (hex_digits[num]);
}

int	ft_puthexxa(va_list args, t_flags *flags)
{
	char			buffer[9];
	int				i;
	unsigned int	num;
	int				printed;

	num = va_arg(args, unsigned int);
	buffer[8] = '\0';
	i = 7;
	printed = 0;
	if (flags->hash && num != 0)
	{
		printed += ft_putstrr("0X");
	}
	if (num == 0)
		return (ft_putc('0'));
	while (num > 0)
	{
		buffer[i--] = base_to_char(num % 16, 'X');
		num /= 16;
	}
	return (printed + ft_putstrr(buffer + (i + 1)));
}

int	ft_puthex(va_list args, t_flags *flags)
{
	char			buffer[9];
	int				i;
	unsigned int	num;
	int				printed;

	num = va_arg(args, unsigned int);
	printed = 0;
	if (flags->hash && num != 0)
	{
		printed += ft_putstrr("0x");
	}
	if (num == 0)
		return (ft_putc('0'));
	buffer[8] = '\0';
	i = 7;
	while (num > 0)
	{
		buffer[i--] = base_to_char(num % 16, 'x');
		num /= 16;
	}
	return (printed + ft_putstrr(buffer + i + 1));
}

int	ft_putnbr(va_list args, t_flags *flags)
{
	t_tool	t;

	t.count = 0;
	t.i = 10;
	t.num = va_arg(args, int);
	if (flags->plus && t.num >= 0)
		t.count += ft_putc('+');
	else if (flags->space && t.num >= 0)
		t.count += ft_putc(' ');
	if (t.num < 0)
	{
		t.count += ft_putc('-');
		t.n = -t.num;
	}
	else
		t.n = t.num;
	t.buffer[11] = '\0';
	if (t.num == 0)
		return (t.count + ft_putc('0'));
	while (t.n > 0)
	{
		t.buffer[t.i--] = t.n % 10 + '0';
		t.n /= 10;
	}
	return (t.count + ft_putstrr(t.buffer + (t.i + 1)));
}

int	ft_putnbr_unsg(va_list args, t_flags *flags)
{
	char			buffer[11];
	int				i;
	unsigned int	num;

	(void)flags;
	num = va_arg(args, unsigned int);
	if (num == 0)
		return (ft_putc('0'));
	i = 10;
	buffer[i] = '\0';
	while (num > 0)
	{
		buffer[--i] = num % 10 + '0';
		num /= 10;
	}
	return (ft_putstrr(buffer + i));
}
