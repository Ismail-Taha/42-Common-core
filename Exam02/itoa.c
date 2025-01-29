#include <stdlib.h>

int n_len(long n)
{
    int i = 0;
    if (n == 0)
        return (1);
    while (n > 0)
    {
        n /= 10;
        i++;
    }
    return (i);
}

char *_itoa(int nbr)
{
    long n = nbr;
    int i = 0;
    char *str = malloc(sizeof(char) * n_len(n) + 1);
    if (!str)
        return (0);
    i = n_len(n);
    str[i--] = 0;
    if (n == 0)
    {
        str[0] = '0';
        return(str);
    }
    while (n > 0)
    {
        str[i] = (n % 10) + 48;
        n /= 10;
        i--;
    }
    return(str);
}