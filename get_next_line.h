#ifndef GNL_GET_NEXT_LINE_H
#define GNL_GET_NEXT_LINE_H
#ifndef BUFFER_SIZE

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#define BUFFER_SIZE 42
#endif BUFFER_SIZE

char *get_next_line(int fd);
int ft_strlen(const char *string);

#endif //GNL_GET_NEXT_LINE_H