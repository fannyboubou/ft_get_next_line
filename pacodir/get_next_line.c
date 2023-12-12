#include "get_next_line.h"
/*
static void ft_free_all(char *string)
{
    int i;

    i = 0;
    while (string[i])
        free(&string[i]);
    free(string);
}
 */
/*
void  *clear_stash(char *stash)
{
    char *stock;
    int i;

    i = 0;
    while (stash[i] != '\n')
        i++;
    i++;
    while (stash[i])
    {
        int j = 0;
        stock[j] = stash[i];
        i++;
        j++;
    }
    stock[i] = '\0';
    ft_memmove(stash, stock, ft_strlen(stock) + 1);
}
 */

char *get_next_line(int fd)
{
    int i;
    ssize_t return_read;
    char *string;
    static char stash[BUFFER_SIZE] = "\0"; // static de base a 0

    if (stash[0] != '\0')
        return_read = ft_strlen(stash);
    else
        return_read = read(fd, stash, BUFFER_SIZE);
    if (return_read == 0 || return_read == -1)
        return (NULL);
    string = malloc(sizeof(char) * ft_strlen(stash) + 2);
    if (string == NULL)
        return (NULL);

    while (return_read > 0)
    {
        i = 0;
        //lecture de tout le buffer size, donc stash peut comprendre des \n
        printf("return read  = %zd\n", return_read);
        printf("stash  %s\n", stash);
        while (i < BUFFER_SIZE)
        {
            if (stash[i] != '\n')
            {
                char substring[2];
                substring[0] = stash[i];
                substring[1] = '\0';
                string = ft_strjoin(string, substring);
                //ft_free_all(temp);
            }
                //printf("string is %s\n", string);
            else if (stash[i] == '\n')
            {
             //   i++;
                string = ft_strjoin(string, "\n");
                ft_memmove(stash, stash + i + 1, (BUFFER_SIZE - i));
                return (string);
            }
            i++;
        }
        return_read = read(fd, stash, BUFFER_SIZE);
    }
    //while (stash[i]) // necessaire ?
    //free (&stash[i]);// necessaire ?
    //free(string); // necessaire ?
    return (string);
}
/*
#include <stdio.h>
#include <fcntl.h>

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
*/