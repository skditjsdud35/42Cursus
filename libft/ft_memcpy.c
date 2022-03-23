#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*cdst;
	char	*csrc;

	cdst = dst;
	csrc = src;
	if (cdst == csrc)
		return (cdst);
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}
