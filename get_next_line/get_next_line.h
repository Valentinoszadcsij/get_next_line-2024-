#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 5
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

char    *get_next_line(int fd);
int ft_len(const char *str);
char *ft_substring(char const *s, unsigned int start, int len);
int ft_strchr(char *str, char c);
char    *ft_strjoin(char *str1, char *str2);
#endif
