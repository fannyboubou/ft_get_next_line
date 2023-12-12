#include "get_next_line.h"

char *get_next_line(int fd)
{
    int i;
    ssize_t return_read;
    char *string;
    static char stash[BUFFER_SIZE] = "\0";

    return_read = 1;
    i = 0;
    string = malloc(sizeof(char) * BUFFER_SIZE + 2); // pour le backshlash n et le backshalsh 0
    if (string == NULL)
        return NULL;
    while (string[i] != '\n')
    {
        while (return_read > 0)
        {
            return_read = (read(fd, stash, BUFFER_SIZE))
        }
    }
}