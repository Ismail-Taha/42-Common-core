#include <stdio.h>
#include <unistd.h>
void    putnbr(int nbr)
{
        char c;

    if (nbr >= 9)
        putnbr(nbr / 10);
     c = nbr % 10 + '0';
    write(STDOUT_FILENO, &c, 1);
}
void    print_hex(int nbr)
{
    char *hex = "0123456789ABCDEF";
    if (nbr >= 16)
        print_hex(nbr / 16);
    write(STDOUT_FILENO, &hex[nbr % 16], 1);
}
int main(void)
{
    putnbr(42424242);
    print_hex(42424278);
}