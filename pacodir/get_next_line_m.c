#include <string.h>
#include "get_next_line.h"

//enelver calloc

char *get_before_newline(const char *s)
{
    char    *res;
    int     i;

    i = 0;
    while(s[i] != '\0' && s[i] != '\n')
        i++;
    if (s[i] != '\0' && s[i] == '\n')
        i++;
    res = calloc(i + 1, sizeof * res);
    if (!res)
        return (NULL);
    i = 0;
    while (s[i] != '\0' && s[i] != '\n')
    {
        res[i] = s[i];
        i++;
    }
    if (s[i] == '\n')
        res[i] = s[i];
    return (res);
}

char *get_after_newline(const char *s)
{
    char    *res;
    int     i;
    int     j;

    j = 0;
    while (s && s[j])
        j++;
    j = 0;
    while (s && s[j])
        j++;
    
}