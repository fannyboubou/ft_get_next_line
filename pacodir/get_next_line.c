#include "get_next_line.h"
//0. on lit et on retournle stash.
// 1. on retourne la fin du stash ou le backslash n.
//2. on join dans la ligne finale a rendre.
// 2.5 on vide ce quon a mis dans la ligne finale : memove : bouger ce quil y a apres le backslash n ou apres le char vide (rien)
// on remet un char vide a la fin de stash
//3. si ya pas eu de fin de read on recommence avec le prochain stash


//0. on lit et on retournle stash.

// 1. on retourne le stash jusquau dernier char ou au le backslash n.
char *get_before_new_line(char const *stash)
{
    char *res;
    int i;

    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] && stash[i] == '\n')
        i++;
    res = malloc(sizeof(char) * i + 1);
    if (res == NULL)
        return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n')
    {
        res[i] = stash[i];
        i++;
    }
    if (stash[i] && stash[i] == '\n')
        res[i] = stash[i];
    res[i] = '\0';
    return (res);
}

char *get_next_line(int fd)
{
    int i;
    ssize_t return_read;
    char *line;
    char *temp;
    static char stash[BUFFER_SIZE] = "\0";

    temp[0] = '\0';
    //if (BUFFER_SIZE <= 0 || fd <= 0 || read(fd, 0, 0) == 0)
    //  return (NULL);
    return_read = read(fd, stash, BUFFER_SIZE);
    if (return_read == 0 || return_read == -1)
        return (NULL);
    while (return_read >= 0)
    {
        char *line = get_before_new_line(stash);
        temp = ft_strjoin(temp, line);
        free(line);

        if (temp && temp[ft_strlen(temp)] == '\n')
        {
            // Adjust the buffer after reading a line
            ft_memmove(stash, stash + ft_strlen(stash), (BUFFER_SIZE - ft_strlen(stash)));
            free(temp);
            return (temp);
        }
        stash[return_read] = '\0';
        return_read = read(fd, stash, BUFFER_SIZE);
    }
    return (temp);
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
