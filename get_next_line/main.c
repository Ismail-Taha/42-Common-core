#include <stdio.h>
#include "get_next_line_bonus.h"

int main(int ac, char **av)
{
    int fd, fd1, fd2;
    (void)ac;

    fd = open(av[1], O_RDONLY);
    fd1 = open(av[2], O_RDONLY);
    fd2 = open(av[3], O_RDONLY);

    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd1));
    printf("%s", get_next_line(fd2));

    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd1));
    printf("%s", get_next_line(fd2));

    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd1));
    printf("%s", get_next_line(fd2));

    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd1));
    printf("%s", get_next_line(fd2));

    close(fd);
    close(fd1);
    close(fd2);

    return 0;
}