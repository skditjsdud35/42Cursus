//#include "libft.h"
#include <stdlib.h>
#include <string.h>
size_t  ft_strlen(const char *s)
{
    size_t	i;

    i = 0;
    while (s[i])
			i++;
    return (i);
}
int main()
{
		const char *s;
		s = NULL;
//		ft_strlen(s);
		strlen(s);
}
