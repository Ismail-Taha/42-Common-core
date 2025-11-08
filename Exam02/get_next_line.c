#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 3


char *get_next_line(int fd)
{
 char buffer[700000];
 static char line[7000000];
    int j = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    static int i;
    size_t readed = 0;
    while(1)
    {
        i = 0;
        readed = read(fd, buffer, BUFFER_SIZE);
        //printf("%s\n", buffer);
        int s = 0;
        if (readed == 0)
            break;
        while (s < readed)
        {
            if (buffer[i] == '\n')
            {
                i++;

                line[j] = '\0';
                return (strdup(line));
            }
            line[j] = buffer[i];
            i++;
            j++;
            s++;
        }
    }
    line[j] = '\0';
    return (strdup(line));
}
int main ()
{
    char *s = get_next_line(open("isma", O_RDONLY));
    printf("%s\n", s);

    s = get_next_line(open("isma", O_RDONLY));
    printf("%s\n", s);

    // s = get_next_line(open("isma", O_RDONLY));
    // printf("%s\n", s);

//     s = get_next_line(open("itoa.c", O_RDONLY));
//     printf("%s\n", s);
}