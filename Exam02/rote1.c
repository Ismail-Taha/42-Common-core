#include <unistd.h>

void put_c(char c)
{
    write (1, &c, 1);
}
void rot1(char *s)
{
    while (*s)
    {
        if ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z'))
            put_c(*s + 1);
        else if (*s == 'z' || *s == 'Z')
            put_c(*s - 25);
        else
            put_c(*s);
        ++s;
    }
}
int main(int ac, char **av)
{
    if (ac == 2)
        rot1(av[1]);
    put_c('\n');
    return (0);
}