#include "get_next_line.h"

//ft_strchr returns index of a character we are looking for, or -1 if its not present or string is NULL;
int ft_strchr(char *str, char c)
{
    int i;

    i = 0;
    if (!str)
        return (-1);
    while (str[i] != '\0')
    {
        if (str[i] == c)
            return (i);
        i++;
    }
        return (i);
}
int ft_len(const char *str)
{
    int i;

    i = 0;
    while (str && str[i] != '\0')
        i++;
    return (i);
}

char *ft_substring(char const *s, unsigned int start, int len)
{
	char			*buffer;
	unsigned int	i;

	i = 0;
	if (!s || start > ft_len(s))
		return (NULL);
	if (len > ft_len(s) - start)
		len = ft_len(s) - start;
	buffer = malloc(sizeof(char) * (len + 1));
	while (i < len && s[start] != '\0')
	{
		buffer[i] = s[start];
		i++;
		start++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char    *ft_strjoin(char *str1, char *str2)
{
    char    *str;
    int     i;
    int     size1;
    int     size2;

    i = 0;
    if (!str1 && !str2)
        return (NULL);
    size1 = ft_len(str1);
    size2 = ft_len(str2);
    if (size1 + size2 == 0)
        return (NULL);
    str = malloc(sizeof(char) * (size1 + size2 + 1));
    str[size1 + size2] = '\0';
    while (str1 && *str1)
        str[i++] = *(str1)++;
    while (str2 && *str2)
        str[i++] = *(str2)++;
    return (str);
}