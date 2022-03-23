#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
        if (fd < 0)
                return ;
        int     i;

        i = 0;
        while (*s)
        {
                write(fd, ft_putchar(*s), 1);
                s++;
        }
	write(1, '\n', 1);
}
