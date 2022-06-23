#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

char	        *return_left(char *backup);
char	        *return_right(char *backup);
char            *read_line(int fd, char *backup);
char            *get_next_line(int fd);
size_t	        ft_strlen(const char *str);
char	        *ft_strjoin(char *s1, char *s2);
char	        *ft_strchr(const char *str, int c);

#endif