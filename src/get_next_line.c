/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:04:29 by aboudarg          #+#    #+#             */
/*   Updated: 2021/11/26 18:04:34 by aboudarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include<fcntl.h>

char	*ft_strdup(const char *s1)
{
	size_t	size;
	size_t	i;
	char	*new_string;

	i = 0;
	size = 0;
	while (s1[size])
		size++;
	new_string = (char *) malloc(sizeof(char) * size + 1);
	if (new_string == NULL)
		return (NULL);
	while (i < size)
	{
		new_string[i] = s1[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

int	check_new_line(char *ptr)
{
	int	i;

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

char	*copy_line(char **saved)
{
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	line = NULL;
	while ((*saved)[i] && (*saved)[i] != '\n')
		i++;
	line = ft_substr(*saved, 0, i + 1);
	temp = ft_substr(*saved, i + 1, ft_strlen(*saved) - (i + 1));
	if (line == NULL || temp == NULL)
		return (NULL);
	free(*saved);
	if (temp[0] == '\0')
	{
		free(temp);
		*saved = NULL;
	}
	else
		*saved = temp;
	return (line);
}

void	read_line(int fd, char **saved)
{
	char	*buffer;
	int		n;
	char	*temp;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	n = read(fd, buffer, BUFFER_SIZE);
	while (n > 0)
	{
		buffer[n] = '\0';
		temp = ft_strjoin(*saved, buffer);
		free(*saved);
		*saved = temp;
		if (check_new_line(*saved))
		{
			free(buffer);
			return ;
		}
		free(buffer);
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		n = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
}

char	*get_next_line(int fd)
{
	static char	*saved;

	if (saved == NULL)
	{
		saved = ft_strdup("");
		if (saved == NULL)
			return (NULL);
	}
	if (!check_new_line(saved))
		read_line(fd, &saved);
	if (*saved == '\0')
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}
	return (copy_line(&saved));
}

/*
int main()
{
	char *line;

int i = 0;
int fd = open("/Users/aboudarg/Cursus/get_next_line_42_1337/gnlTester/files/41_no_nl", O_RDWR);
while (i < 2)
{
	line = get_next_line(fd);
	printf("%s",line);
	free(line); 
	i++;
}
while(1)
;
	return (0);
}
*/
