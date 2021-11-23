#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int ft_strchr(char *ptr)
{

	int i;

	i = 0;
	if (ptr == NULL)
		return (0);
	while (ptr[i])
	{
		if (ptr[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t src_size;

	i = 0;
	src_size = ft_strlen(src);
	if (dstsize)
	{
		while (src_size > i && (i + 1) < dstsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_size);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int size_s;
	char *substr;

	if (!s)
		return (NULL);
	size_s = ft_strlen(s);
	if (start >= size_s)
	{
		substr = (char *)malloc(1);
		*substr = '\0';
		return (substr);
	}
	if (len > size_s)
		len = size_s - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

char *ft_copy(char **result)
{
	int i;
	char *temp;
	char *line;

	i = 0;
	temp = NULL;
	if(**result == '\0')
		return (0);

	while ((*result)[i] && (*result)[i] != '\n')
		i++;
	line = ft_substr(*result, 0, i + 1);
	if(*(*result + i) != '\0')
	{
		temp = ft_strdup(*result + i + 1);
		free(*result);
	}
	else
	{
		free(*result);
		*result = NULL;
	}
	*result = temp;
	return (line);
}

char *get_next_line(fd)
{
	static char *result = NULL;
	char *line;
	char *buffer;
	int n;

	line = NULL;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (result == NULL)
		result = ft_strdup("");
	if (ft_strchr(result))
	{
		free(buffer);
		return ft_copy(&result);
	}
	else
	{
		n = read(fd, buffer, BUFFER_SIZE);
		while (n > 0)
		{
			buffer[n] = '\0';
			result = ft_strjoin(result, buffer);
			if (ft_strchr(result))
			{
				free(buffer);
				return (ft_copy(&result));
			}
			else
				n = read(fd, buffer, BUFFER_SIZE);
		}
	}
	if(n == -1)
	{
		free(line);
		return NULL;
	}
	if(result)
		line = ft_copy(&result);
	

	free(buffer);
	return (line);
}
/*
int main()
{
	int fd = open("/Users/aboudarg/Cursus/get_next_line_42_1337/gnlTester/files/41_no_nl", O_RDWR);
	char *line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	system ("leaks a.out");
	return (0);
}
*/