#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 1000

char	        *return_left(char *backup);
char	        *return_right(char *backup);
char            *read_line(int fd, char *backup);
char            *get_next_line(int fd);
size_t	        ft_strlen(const char *str);
char	        *ft_join(char *s1, char *s2);
char	        *ft_strchr(const char *str, int c);

#endif
