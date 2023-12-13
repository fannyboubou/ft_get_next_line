#include "get_next_line.h"

char *get_next_line(int fd)
{
	int i;
	ssize_t return_read;
	char *string;
	static char stash[BUFFER_SIZE] = "\0";

//	if (stash[0] != '\0')
//		return_read = ft_strlen(stash);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	return_read = read(fd, stash, BUFFER_SIZE);
	if (return_read == 0 || return_read == -1)
		return (NULL);
	string = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (string == NULL)
		return (NULL);
//	string[0] = '\0';
	i = -1;
	while (return_read > 0)
	{
		while (stash[++i])
		{
			 if (stash[i] != '\n')
			{
				string[i] = stash[i];
//				char substring[2];
//				substring[0] = stash[i];
//				substring[1] = '\0';
//				string = ft_strjoin(string, substring);
			}
			else
			{
				string[i] = stash[i];
				ft_memmove(stash, stash + i, ((BUFFER_SIZE - i)));
				return (string);
				//break ;
//				string = ft_strjoin(string, "\n");

				return (string);
			}
//			i++;
		}
		return_read = read(fd, stash, BUFFER_SIZE);
	}
	stash[return_read] = '\0';
	//stash -> enlever les charactere avant i
	//ft_memmove(stash, stash + i + 1, ((BUFFER_SIZE - i) + 1));
	// while (*stash != '\n')
	// *stash++;
	//
	return (string);
}

#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd;
//	char *myfile;
	char *line;

//	myfile = "/home/faboussa/getnextline/multiple_line_with_nl.txt";
	//myfile = "/home/faboussa/getnextline/multiple_line_with_nl.txt";
	fd = open("/home/faboussa/getnextline/line_around_10.txt", O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
