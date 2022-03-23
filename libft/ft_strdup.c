#include "libft.h"

char *ft_strdup(const char *s1)
{
	size_t	size;
	size_t	i;
	char 	*s2;

	size = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (size + 1));
	i = 0;
	if (!s2)
		return (0);

	while(i < size)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}
