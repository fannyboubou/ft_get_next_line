#include "get_next_line.h"

int ft_strlen(const char *string)
{
	int i;
	i = 0;
	while (string[i])
		i++;
	return (i);
}


void    *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char   *dest_byte;
    unsigned char   *src_byte;

    if (dest == NULL && src == NULL)
        return (dest);
    dest_byte = (unsigned char *)dest;
    src_byte = (unsigned char *)src;
    if (dest_byte < src_byte)
        ft_memcpy(dest, src, n);
    else
    {
        while (n > 0)
        {
            dest_byte[n - 1] = src_byte[n - 1];
            n--;
        }
    }
    return (dest);
}

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t                  i;
    unsigned char   *byte_dest;
    unsigned char   *byte_src;

    byte_dest = (unsigned char *) dest;
    byte_src = (unsigned char *) src;
    i = 0;
    if (dest == NULL && src == NULL)
        return (dest);
    while (i < n)
    {
        byte_dest[i] = byte_src[i];
        i++;
    }
    return (dest);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char            *new_string;
    size_t          total_length;

    total_length = ft_strlen(s1) + ft_strlen(s2);
    new_string = malloc(sizeof(char) * total_length + 1);
    if (new_string == NULL)
        return (0);
    ft_strlcpy(new_string, s1, total_length);
    ft_strlcat(new_string, s2, total_length);
    return (new_string);
}

size_t  ft_strlcpy(char *dest, const char *src, size_t size)
{
    size_t  i;
    size_t  return_value;

    i = 0;
    if (size != 0)
    {
        while (i < (size - 1) && src[i] != '\0')
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }
    return_value = ft_strlen(src);
    return (return_value);
}

size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t  c;
    size_t  d;

    if (dstsize <= ft_strlen(dst))
        return (dstsize + ft_strlen(src));
    c = ft_strlen(dst);
    d = 0;
    while (src[d] != '\0' && c + 1 < dstsize)
    {
        dst[c] = src[d];
        c++;
        d++;
    }
    dst[c] = '\0';
    return (ft_strlen(dst) + ft_strlen(&src[d]));
}