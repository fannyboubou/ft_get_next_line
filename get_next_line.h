#ifndef GNL_GET_NEXT_LINE_H
#define GNL_GET_NEXT_LINE_H
#ifndef BUFFER_SIZE

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#define BUFFER_SIZE 2

char *get_next_line(int fd);
int ft_strlen(const char *string);
void    *ft_memcpy(void *dest, const void *src, size_t n);
void    *ft_memmove(void *dest, const void *src, size_t n);
char    *ft_strjoin(char const *s1, char const *s2);
size_t  ft_strlcpy(char *dest, const char *src, size_t size);
size_t  ft_strlcat(char *dst, const char *src, size_t dstsize);
void    *ft_bzero(void *s, size_t n);
void    *ft_calloc(size_t nmemb, size_t size);
void    *ft_memset(void *s, int c, size_t n);

#endif //BUFFER_SIZE
#endif //GNL_GET_NEXT_LINE_H