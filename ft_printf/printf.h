/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:51:00 by isallali          #+#    #+#             */
/*   Updated: 2024/12/06 14:41:28 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_flags
{
	int	space;
	int	hash;
	int	plus;
	int	index;
	int	ret;
	int	validation;
}	t_flags;

typedef struct s_tool
{
	int				num;
	unsigned int	n;
	unsigned int	count;
	char			buffer[12];
	int				i;
}	t_tool;

typedef struct prf_format
{
	char	symbol;
	int		(*puts)(va_list arg, t_flags *flags);
}	t_format;

char	*ft_strchr(char *s, int i);
char	base_to_char(unsigned long num, char c);
int		ft_putc(char c);
int		ft_putstrr(char *str);

int		ft_putchar(va_list args, t_flags *flags);
int		ft_putstr(va_list args, t_flags *flags);
int		ft_putnbr(va_list args, t_flags *flags);
int		ft_putnbr_unsg(va_list args, t_flags *flags);
int		ft_puthex(va_list args, t_flags *flags);
int		ft_puthexxa(va_list args, t_flags *flags);
int		ft_putptr(va_list args, t_flags *flags);

int		ft_printf(const char *format, ...);
int		process(const char *format, t_format *printers,
			va_list args, int *count);

#endif /*PRINTF_H*/
