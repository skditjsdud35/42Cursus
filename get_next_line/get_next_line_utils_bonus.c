#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	i = 0;
	j = 0;
	s1_len = (int)ft_strlen(s1);
	s2_len = (int)ft_strlen(s2);
	str = malloc (s1_len + s2_len + 1);
	if (!str)
		return (0);
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < s2_len)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if ((char)c == str[i])
		{
			return ((char *)(str + i));
		}
		i++;
	}
	if (c == 0)
		return ((char *)(str + i));
	return (0);
}