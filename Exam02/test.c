#include <unistd.h>
#include <stdlib.h>

int ft_putchar(char c)
{
    return(write(1, &c, 1));
}

int ft_putstr(char *str)
{
    int cn = 0;
    if (!str)
        str = "(null)";
    while (*str)
    {
        cn += ft_putchar(*str);
        str++;
    }
    return (cn);
}

int ft_putnbr(int n)
{
    int cn = 0;

    if (n == -2147483648)
        return (ft_putstr("-2147483648"));
        if (n < 0)
        {
            cn += ft_putchar('-');
            n = -n;
        }
        if (n > 0)
            cn += ft_putnbr(n / 10);
        cn += ft_putchar((n % 10) + '0');
        return (cn);
}

int ft_puthex(unsigned int n)
{
    int cn = 0;

    if (n >= 16)
        cn += ft_puthex(n / 16);
    if ((n % 16) < 10)
        cn += ft_putchar((n % 16) + '0');
    else
        cn += ft_putchar((n % 16) - 10 + 'a');
    return (cn);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int cnt = 0;
    int i = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 'd')
                cnt += ft_putnbr(va_arg(args, int));
            else if (format[i] == 's')
                cnt += ft_putstr(va_arg(args, char *));
            else if (format[i] == 'x')
                cnt += ft_puthex(va_arg(args, unsigned int));
        }
        else
            cnt += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (cnt);
}