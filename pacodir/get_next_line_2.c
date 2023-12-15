#include "get_next_line.h"

void ft_clear_stash(char *stash)
{
    int i;
    i = 0;
    while (stash[i])
    {
        if (stash[i] != '\n')
            i++;
        else
            ft_memmove(stash, stash + i + 1, (BUFFER_SIZE - i));
        i++;
    }
}

char *ft_line(char *stash)
{
    char *line;
    int i;

    i = 0;
    if (!stash[i])
        return (NULL);
    line = malloc(sizeof(char) * (ft_strlen(stash) + 1));
//remplacer par ftstrlen;
    i = 0;
    while (stash[i] && stash[i] != '\n')
    {
        line[i] = stash[i];
        i++;
    }
    if (stash[i] && stash[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

char *get_next_line(int fd)
{
    ssize_t return_read;
    char *line;
    char *string;
    static char stash[BUFFER_SIZE + 1] = "\0";
int i;
    if (BUFFER_SIZE == 0 || fd == 0)
        return (NULL);
    if (stash[0] != '\0')
        return_read = ft_strlen(stash);
    else
        return_read = read(fd, stash, BUFFER_SIZE);
    string = malloc(sizeof(char) * ft_strlen(stash) + 2);
    if (string == NULL)
        return (NULL);
    if (return_read == 0 || return_read == -1)
        return (NULL);
    string[0] = '\0';
    while (return_read > 0)
    {
        i = 0;
        while (stash[i])
        {
            if (stash[i] != '\n')
            {
                line = ft_line(stash);
                string = ft_strjoin(string, line);
            } else
            {
                ft_clear_stash(stash);
                return (string);
            }
            i++;
        }
        return_read = read(fd, stash, BUFFER_SIZE);
    }
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
