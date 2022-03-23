#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
		unsigned char	*ub;
		size_t			i;

		ub = b;
		i = 0;
		while (i < len)
		{
				ub[i] = c;
				i++;
		}
		return (b);
}		
