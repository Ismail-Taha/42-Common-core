#include <unistd.h>

void put_c(char c)
{
    write (1, &c, 1);
}

int main(int ac, char **av)
{
    int i = 0;

    if (ac == 2)
    {
        while (av[1][i])
        {
            if (av[1][i] >= 'A' && av[1][i] <= 'Z')
            {
                av[1][i] += 32;
                write(1, "_", 1);
            }
            write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}