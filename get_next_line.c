#include "get_next_line.h"
// fd = 0 = entree standard = stdin
// fd = 1 = sortie standart = stdout
// fd  = 2 = stderr
char    *get_next_line(int fd)
{
	ssize_t 		i;
    int return_read;
	char	*string;
	static char	stash[BUFFER_SIZE] = "\0";

    string = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (string == NULL)
        return (NULL);
    return_read = read(fd, stash, BUFFER_SIZE);
	if ((return_read == 0) || (return_read == -1))
		return (NULL);
	i = 0;
    while (i <= BUFFER_SIZE && stash[i] != '\n')
	{
		string[i] = stash[i];
		if (return_read <= 0)
			return (NULL);
        i++;
	}
	//while (stash[i]) // necessaire ?
		//free (&stash[i]);// necessaire ?
	//free(string); // necessaire ?
	string[i] = '\0';
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
	printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
	close(fd);
	return (EXIT_SUCCESS);
}
