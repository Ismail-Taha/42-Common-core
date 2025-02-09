#include <stdlib.h>


//ft_strdup
#define BUFFER_SIZE 32

char *get_next_line(int fd)
{
    static buffer[70000];
    static line[70000];

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    int i = 0;
    int j = 0;
    size_t readed;
    while(1)
    {
        readed = read(fd, buffer, BUFFER_SIZE);
        if (readed == 0)
            break;
        while (i < readed)
        {
            if (buffer[i] == '\n')
            {
                line[j] = '\0';
                return (ft_strdup(line));
            }
            line[j] = buffer[i];
            i++;
            j++;
        }
    }
    line[j] = '\0';
    return (ft_strdup(line));
}