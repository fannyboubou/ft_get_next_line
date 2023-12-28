#include "get_next_line.h"

char	*get_reminder(char **str)
{
    char	*reminder;
    int		rlen;

    rlen = ft_strlen(*str);
    reminder = ft_substr(*str, 1, rlen);
    free(*str);
    *str = NULL;
    return (reminder);
}

char *func(char **line, char **tmp)
{
    *line = ft_substr(*tmp, 0, 1);
    *tmp = get_reminder(tmp);
    return (*line);
}

char *get_before_new_line(char const *stash)
{
    char *res;
    int i;

    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] && stash[i] == '\n')
        i++;
    res = malloc(sizeof(char) * (i + 1));
    if (res == NULL)
        return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n')
    {
        res[i] = stash[i];
        i++;
    }
    if (stash[i] && stash[i] == '\n')
    {
        res[i] = stash[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

char *get_next_line(int fd)
{
    ssize_t return_read;
    char *line;
    char *final;
    static char stash[BUFFER_SIZE] = "\0";

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = malloc(sizeof(char) * 2);
    line[0] = '\0';
    line[1] = '\0';
    if (stash[0] != '\0')
        return_read = ft_strlen(stash);
    else
        return_read = read(fd, stash, BUFFER_SIZE);
    if (return_read <= 0)
    {
        free(line);
        return (NULL);
    }
    while (return_read > 0)
    {
        line = ft_strjoin(line, get_before_new_line(stash));
        if (line == NULL)
            return (NULL);
        if (line[ft_strlen(line) - 1] == '\n')
            return (func(&final, &line));
        return_read = read(fd, stash, BUFFER_SIZE);
        stash[return_read] = '\0';
    }
    free(line);
    return (NULL);
}

#include <stdio.h>
#include <fcntl.h>

    int main()
    {
        int fd;
        char *myfile;

        myfile = "/home/fanny/getnextlinefanny/1char.txt";
        fd = open(myfile, O_RDONLY);
        if (fd < 0)
            return (EXIT_FAILURE);
        printf("fd file is %d\n", fd);
        // get_next_line(fd);
        //get_next_line(fd);
        //get_next_line(fd);
        printf("first line is %s\n", get_next_line(fd));
        printf("second line is %s", get_next_line(fd));
        printf("third line is %s", get_next_line(fd));
        printf("fourth line is %s", get_next_line(fd));
        printf("fifth line is %s", get_next_line(fd));
        printf("sixth line is %s", get_next_line(fd));
        printf("seventh line is %s", get_next_line(fd));
        printf("eighth line is %s", get_next_line(fd));
        printf("ninth line is %s", get_next_line(fd));
        close(fd);
        return (EXIT_SUCCESS);
    }

