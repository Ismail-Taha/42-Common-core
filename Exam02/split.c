#include <stdlib.h>

int check(char c)
{
    if (c == 9 || c == 10 || c == 32 || c == 0)
        return (0);
    return (1);
}
int countw(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i])
    {
        while (str[i] && !(check(str[i])))
            i++;
        if (str[i] != 0)
            count++;
        while (str[i] && check(str[i]));
            i++;
    }
    return (count);
}
int lenght(char *str)
{
    int i = 0;

    while (str[i] && check(str[i]))
        i++;
    return (str);
}

char *stdup(char *str)
{
    int i = 0;
    int len = lenght(str);
    char *cpy = malloc(sizeof(char) * len + 1);

    while (i < len)
    {
        cpy[i] = str[i];
        i++;
    }
    cpy[i] = 0;
    return (cpy);
}
char **ft_split(char *str)
{
    int i = 0;
    char **strs = malloc(sizeof(char *) * countw(str) + 1);

    while (*str)
    {
        while (*str && !(check(*str)))
            str++;
        if (*str)
        {
            strs[i] = stdup(str);
            i++;
        }
        while (*str && check(*str))
            str++;
    }
    strs[i] = 0;
    return(strs);
}