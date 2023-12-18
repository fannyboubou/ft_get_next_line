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
    {
        res[i] = stash[i];
        i++; //javance de 1 comme dans le while
    }
    res[i] = '\0';
    return (res);
}

char *get_next_line(int fd)
{
    ssize_t return_read;
    char *temp;
    char *line;
    static char stash[BUFFER_SIZE] = "\0";

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = malloc(sizeof(char));
    line[0] = '\0';
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
        temp = get_before_new_line(stash);
        if (temp == NULL)
            return (NULL);
        line = ft_strjoin(line, temp);
        if (line == NULL)
            return (NULL);
        free(temp);

        if (line[ft_strlen(line) - 1] == '\n')
        {
            // Adjust the buffer after reading a temp
            ft_memmove(stash, stash + ft_strlen(line), (BUFFER_SIZE - ft_strlen(stash)));
            break;
        }
        return_read = read(fd, stash, BUFFER_SIZE);
       //ft_memmove(stash, stash + ft_strlen(stash) + 1, (BUFFER_SIZE - ft_strlen(stash)));
        stash[return_read] = '\0';
    }
   stash[BUFFER_SIZE - ft_strlen(stash)] = '\0';
    return (line);
}


#include <stdio.h>
#include <fcntl.h>

//    int main()
//    {
//        int fd;
//        char *myfile;
//
//        myfile = "/home/fanny/getnextlinefanny/multiple_nl.txt";
//        fd = open(myfile, O_RDONLY);
//        if (fd < 0)
//            return (EXIT_FAILURE);
//        printf("fd file is %d\n", fd);
//        // get_next_line(fd);
//        //get_next_line(fd);
//        //get_next_line(fd);
//        printf("first line is %s", get_next_line(fd));
//        printf("second line is %s", get_next_line(fd));
//        printf("third line is %s", get_next_line(fd));
//        printf("fourth line is %s", get_next_line(fd));
//        printf("fifth line is %s", get_next_line(fd));
//        close(fd);
//        return (EXIT_SUCCESS);
//    }

