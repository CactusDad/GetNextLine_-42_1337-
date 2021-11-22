#include "get_next_line.h"

size_t	ft_strlen(const char *dst)
{
	size_t	len;

	len = 0;
	while (dst[len])
		len++;
	return (len);
}
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size_d;
	size_t	size_s;

	size_s = ft_strlen(src);
	if (dst == NULL && dstsize == 0)
		return (size_s);
	i = 0;
	size_d = ft_strlen(dst);
	if (dstsize > size_d)
	{
		while (size_s > i && i + 1 < dstsize - size_d && src[i] != '\n')
		{
			dst[i + size_d] = src[i];
			i++;
		}
		if (src[i] == '\n')
			dst[i + size_d++] = '\n';
		dst[i + size_d] = '\0';
		return (size_d + size_s);
	}
	return (dstsize + size_s);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == src)
		return (dst);
		i = 0 ;
	ptr_dst = (unsigned char *) dst;
	ptr_src = (unsigned char *) src;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return ((void *)ptr_dst);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*full_string;
	size_t	full_size;

	if (s1 == NULL || s2 == NULL)
	{
		full_string = (char *) malloc(1);
		if (full_string == NULL)
			return (NULL);
		*full_string = '\0';
		return (full_string);
	}
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	full_size = (size_s1 + size_s2 + 1) * sizeof(char);
	full_string = (char *)malloc(full_size);
	if (full_string == NULL)
		return (NULL);
	ft_memcpy(full_string, s1, size_s1);
	*(full_string + size_s1) = '\0';
	ft_strlcat(full_string, s2, full_size + 1);
	free((char *)s1);
	return (full_string);
}
