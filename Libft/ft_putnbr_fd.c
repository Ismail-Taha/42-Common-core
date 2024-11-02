#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    char    *nb;

    nb = ft_itoa(n);
    if (nb)
    {
        write(fd, nb, ft_strlen(nb));
        free(nb);
    }
}