#include "get_next_line.h"

size_t	ft_strlen(const char *dst)
{
	size_t	len;

	len = 0;
	while (dst[len])
		len++;
	return (len);
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
		while (size_s > i && i + 1 < dstsize - size_d )
		{
			dst[i + size_d] = src[i];
			i++;
		}
		dst[i + size_d] = '\0';
		return (size_d + size_s);
	}
	return (dstsize + size_s);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
        size_t  i;
        size_t  src_size;

        i = 0;
        src_size = ft_strlen(src);
        if (dstsize)
        {
                while (src_size > i && (i + 1) < dstsize)
                {
                        *dst++ = *src++;
                        i++;
                }
                *dst++ = '\0';
        }
        return (src_size);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        unsigned int    size_s;
        char                    *substr;

        if (!s)
                return (NULL);
        size_s = ft_strlen(s);
        if (start >= size_s)
        {
                substr = (char *) malloc(1);
                *substr = '\0';
                return (substr);
        }
        if (len > size_s)
                len = size_s - start;
                substr = (char *) malloc((len + 1) * sizeof(char));
        if (substr == NULL)
                return (NULL);
        ft_strlcpy(substr, s + start, len + 1);
        return (substr);
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
	ft_strlcpy(full_string, s1, size_s1 + 1);
	ft_strlcat(full_string, s2, full_size + 1);
	return (full_string);
}
