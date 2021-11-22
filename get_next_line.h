#define GET_NEXT_LINE_
#ifdef GET_NEXT_LINE_
#include<unistd.h>
#include<stdlib.h>
#include<stddef.h>
/*#define BUFFER_SIZE 250*/
size_t	ft_strlen(const char *dst);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char    *ft_strdup(const char *str);
char    *get_next_line(int fd);
#endif