/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunahn <sunahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:05:57 by sunahn            #+#    #+#             */
/*   Updated: 2022/03/24 20:52:57 by sunahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_string_count(char *str, char *charset)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if ((check_charset(str[i], charset) == 1)
			&& (check_charset(str[i + 1], charset) == 0))
			count++;
		else if (i == 0 && check_charset(str[i], charset) == 0)
			count++;
		i++;
	}
	return (count);
}

void	ft_strcpy(char *result, char *str, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		result[idx] = str[idx];
		idx++;
	}
	result[idx] = '\0';
}
void	ft_free_all(char **str)
{
	int	i;
	
	i = 0;
	while (!str[i])
		free(str[i++]);
    free(str);
	return (0);
}
char	**ft_split(char const *str, char *c)
{
	char	**result;
	int		idx;
	int		i;
	int		j;

	result = (char **)malloc(sizeof(char *) \
			* (get_string_count(str, charset) + 1));
	if (!result)
		return (0);
	idx = 0;
	while (*str != '\0')
	{
		i = 0;
		j = 0;
		if (check_charset(*str, charset) == 0)
		{
			while (check_charset(*(str + i), charset) == 0
				&& *(str + i) != '\0')
				i++;
			result[idx] = (char *)malloc(sizeof(char) * i + 1);
			if (!result[idx])
				return (ft_free_all(result));
			ft_strcpy(result[idx++], str, i);
			str += i - 1;
		}
		str++;
	}
	result[idx] = 0;
	return (result);
}
