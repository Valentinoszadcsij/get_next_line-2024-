#include "get_next_line.h"

char	*ft_split_remaining(char *buffer)
{
	char	*remainder;
	int		i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
		return (NULL);
	if (i + 1 < ft_len(buffer))
		return (ft_substring(buffer, i + 1, ft_len(buffer) - i));//word\n\0
	return (NULL);
}

char	*ft_split_return(char *buffer)
{
	char	*return_line;
	int		i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	return_line = ft_substring(buffer, 0, i);
	return (return_line);
}

char	*get_one_line(int fd, char *buffer)
{
	int	read_status;
	int	i;
	char	read_value[BUFFER_SIZE + 1];
	char	*temp;

	i = 0;
	read_status = 1;
	while(read_status > 0)
	{
		read_status = read(fd, read_value, BUFFER_SIZE);
		read_value[read_status] = '\0';
		temp = buffer;
		buffer = ft_strjoin(buffer, read_value);
		free(temp);
		if(ft_strchr(buffer, '\n') >= 0)
			return(buffer);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*return_line;
	char		*temp;

	return_line = NULL;
	if (buffer)
		buffer = get_one_line(fd, buffer);
	else
	{
		buffer = NULL;
		buffer = get_one_line(fd, buffer);
	}
	if (buffer)
	{	
		return_line = ft_split_return(buffer);
		temp = buffer;
		buffer = ft_split_remaining(buffer);
		if (temp)
			free(temp);
	}
	return (return_line);
}