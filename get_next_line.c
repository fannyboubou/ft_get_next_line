#include "get_next_line.h"

char    *get_next_line(int fd)
{
	int		i;
    char	*string;
	char	*string2;
	static int		new_buffer_size;
	char c;

	if ((fd == 0) || (fd == -1))
		return (NULL);
	i = 0;
    string = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (string == NULL)
		return (NULL);
    while (read(fd, &c, BUFFER_SIZE) > 0 && c != '\n')
	{
		string[i++] =  c;// pb avec buffer size ici
		if (read(fd, &c, BUFFER_SIZE <= 0))
			return (NULL);
		if (i == BUFFER_SIZE)
		{
			new_buffer_size += BUFFER_SIZE;
			string2 = realloc(string, sizeof(char) * ft_strlen(string) + new_buffer_size + 1);
			if (string2 == NULL)
				return (NULL);
			string2[i++] = c;
		}
	}
	while (string[i])
		free (&string[i]);
	free(string);
	close(fd);
	string2[i] = '\0';
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
	close(fd);
	return (EXIT_SUCCESS);
}
