#include "get_next_line.h"

char *get_next_line(int fd)
{
    int i;
    ssize_t return_read;
    char *string;
    static char stash[BUFFER_SIZE] = "\0";
    char substring[2];

    if (BUFFER_SIZE == 0 || fd == 0)
        return (NULL);
    if (stash[0] != '\0')
        return_read = ft_strlen(stash);
    else
        return_read = read(fd, stash, BUFFER_SIZE);
    if (return_read == 0 || return_read == -1)
        return (NULL);
    string = malloc(sizeof(char) * ft_strlen(stash) + 2);
    if (string == NULL)
        return (NULL);
    string[0] = '\0';
    while (return_read > 0)
    {
        i = 0;
        if (stash[i] != '\n')
        {
            while (stash[i])
            {
                substring[0] = stash[i];
                substring[1] = '\0';
                i++;
                // faire un pointeur temp de string que je garde et je free le reste ou free dans strjoin
            }
            string = ft_strjoin(string, substring);
        }
        else
        {
            string = ft_strjoin(string, "\n");
            ft_memmove(stash, stash + i + 1, (BUFFER_SIZE - i));
            return (string);
        }
    }
    return_read = read(fd, stash, BUFFER_SIZE);
    stash[return_read] = '\0';
    return (string);
}

#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd;
    char *myfile;

    myfile = "/home/fanny/getnextlinefanny/fichier.txt";
    fd = open(myfile, O_RDONLY);
    if (fd < 0)
        return (EXIT_FAILURE);
    printf("fd file is %d\n", fd);
    // get_next_line(fd);
    //get_next_line(fd);
    //get_next_line(fd);
    printf("first line is %s", get_next_line(fd));
    printf("second line is %s", get_next_line(fd));
    printf("third line is %s", get_next_line(fd));
    printf("fourth line is %s", get_next_line(fd));
    printf("fifth line is %s", get_next_line(fd));
    close(fd);
    return (EXIT_SUCCESS);
}
