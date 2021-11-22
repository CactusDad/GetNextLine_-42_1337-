#include "get_next_line.h"
 #include <fcntl.h>
 #include<stdio.h>
 #include<string.h>

int check_sign(char *buffer, char *result)
{
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    while (buffer[i])
    {
        if (buffer[i] == '\n')
        {
           i++; 
            memset(result,0, BUFFER_SIZE);
           while (buffer[i])
           {
                result[j++] = buffer[i];
               i++;
           }
            result[j] = '\0';
            return (1);
        }
        i++;
    }
    return (0);
}

char    *get_next_line(int fd)
{
    char        *buffer;
    char        *line;
    static char result[BUFFER_SIZE + 1];
    int         n;
    int         stats;

    buffer = malloc(sizeof(char)* BUFFER_SIZE + 1);
    stats = 0;
    line = ft_strdup("\0");
            if (!(*result))
                *result = '\0';
            else
            {
               ft_memcpy(buffer, result, ft_strlen(result));
                buffer[ft_strlen(result)] = '\0';
               line = ft_strjoin(line, buffer); 
                if (check_sign(buffer, result))
                {
                    free(buffer);
                    return (line);
                }
            }
        n = read(fd, buffer, BUFFER_SIZE);
            buffer[n] = '\0';
        while (n > 0)
        {
           
            line = ft_strjoin(line, buffer);// should free line in strjoin 
            if (check_sign(buffer, result))
            {
                //free(buffer);
                break ; 
            }
        n = read(fd, buffer, BUFFER_SIZE);
        }
     
   if(n <= 0)
    {
       free(line);
        line = NULL;
    }
    free(buffer);
    return (line);
}
/*
int main()
{
    int fd = open("/Users/aboudarg/Cursus/get_next_line/gnlTester/files/41_with_nl",O_RDWR);
char *line = get_next_line(fd);
    printf("%s",line);
   line = get_next_line(fd);
   printf("%s",line);
  line = get_next_line(fd);
   printf("%s",line);
   line = get_next_line(fd);
   printf("%s",line);
    return (0);
}
*/