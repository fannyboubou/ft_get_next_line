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
