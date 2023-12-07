#include "get_next_line.h"

char    *get_next_line(int fd)
{
    while (read(fd, buffer, 200) != '\0')
        ft_
}

int main()
{
    int fd;
    size_t nbyte;
    char buf[20];

    nbyte = sizeof(buf);
    fd = 2;
    if ((read(fd, buf, nbyte) == 0) || ((read(fd, buf, nbyte) == -1)))
        return (0);
    else
    {
        while (read(fd, buf, nbyte) != '\0')
            get_next_line(2);
    }
}
