#include "get_next_line.h"

//temp est trop long, ce nest pas logique
static char *ft_save_chars_before_end_of_array(char *stash)
{
    int i;
    i = 0;
    char *temp;
    while (stash[i] != '\0')
    {
        printf("stash de i  = %c\n", stash[i]);
        temp[i] = stash[i];
        i++;
    }
    return (temp);
}

static void ft_free_all(char *string)
{
    int i;

    i = 0;
    while (string[i])
        free(&string[i]);
    free(string);
}

char *get_next_line(int fd)
{
    int i;
    ssize_t return_read;
    char *string;
    char *temp;
    static char stash[BUFFER_SIZE] = "\0";

    return_read = 1;
    i = 0;
    string = malloc(sizeof(char) * ft_strlen(stash) + 2);
    if (string == NULL)
        return (NULL);

    while (string[i] != '\n')
    {
        while (return_read > 0)
        {
            //lecture de tout le buffer size, donc stash peut comprendre des \n
            return_read = read(fd, stash, BUFFER_SIZE);
            if ((return_read == 0) || (return_read == -1))
                return (NULL);
            printf("return read  = %zd\n", return_read);
            while (i <= BUFFER_SIZE)
            {
                if (stash[i] != '\n')
                {
                    //temp a revoir.
                    temp = ft_save_chars_before_end_of_array(stash);
                    string = ft_strjoin(temp, stash);
                    //ft_free_all(temp);
                }
                printf("string is %s\n", string);
                // cett partie ci dessous a lair de fonctionner
                if (stash[i] == '\n')
                    ft_memmove(stash, stash + i, ft_strlen(stash + i));
                printf("stash is %s\n", stash);
                i++;
            }
        }
    }
    //while (stash[i]) // necessaire ?
    //free (&stash[i]);// necessaire ?
    //free(string); // necessaire ?
    return (string);
}

#include <stdio.h>

int main()
{
    int fd;
    char *myfile;

    myfile = "/home/faboussa/getnextline/fichier.txt";
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
    close(fd);
    return (EXIT_SUCCESS);
}
