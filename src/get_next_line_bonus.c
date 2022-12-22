/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:05:47 by aboudarg          #+#    #+#             */
/*   Updated: 2021/11/26 18:05:50 by aboudarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include<fcntl.h>
#include<limits.h>

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

char	*copy_line(char **backup)
{
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	line = NULL;
	while ((*backup)[i] && (*backup)[i] != '\n')
		i++;
	line = ft_substr(*backup, 0, i + 1);
	temp = ft_substr(*backup, i + 1, ft_strlen(*backup) - (i + 1));
	if (line == NULL || temp == NULL)
		return (NULL);
	free(*backup);
	if (temp[0] == '\0')
	{
		free(temp);
		*backup = NULL;
	}
	else
		*backup = temp;
	return (line);
}

void	read_line(int fd, char **backup)
{
	char	*buffer;
	int		n;
	char	*temp;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	n = read(fd, buffer, BUFFER_SIZE);
	while (n > 0)
	{
		buffer[n] = '\0';
		temp = ft_strjoin(*backup, buffer);
		free(*backup);
		*backup = temp;
		if (check_new_line(*backup))
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
	static char	*backup[OPEN_MAX];

	if (fd < 0)
		return (NULL);
	if (backup[fd] == NULL)
	{
		backup[fd] = ft_strdup("");
		if (backup[fd] == NULL)
			return (NULL);
	}
	if (!check_new_line(backup[fd]))
		read_line(fd, &backup[fd]);
	if (backup[fd] && backup[fd][0] == '\0')
	{
		free(backup[fd]);
		backup[fd] = NULL;
		return (NULL);
	}
	return (copy_line(&backup[fd]));
}

/*
int main()
{
	char *line;

int i = 0;
int fd = open("/Users/aboudarg/Cursus/get_next_line_42_1337/gnlTester/files/empty", O_RDWR);
while (i < 2)
{
	line = get_next_line(10240);
	printf("%s",line);
	free(line); 
	i++;
}
	return (0);
}
*/
