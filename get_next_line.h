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

char *get_next_line(int fd);
int ft_strlen(const char *string);
void    *ft_memcpy(void *dest, const void *src, size_t n);
void    *ft_memmove(void *dest, const void *src, size_t n);

#endif //BUFFER_SIZE
#endif //GNL_GET_NEXT_LINE_H