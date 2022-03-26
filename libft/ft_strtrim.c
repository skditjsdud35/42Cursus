/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunahn <sunahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:37:45 by sunahn            #+#    #+#             */
/*   Updated: 2022/03/26 16:42:13 by sunahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	e_trim(char const *s1, char const *set)
{
	size_t	end;
	size_t	i;

	i = 0;
	end = ft_strlen(set) - 1;
	while (i < ft_strlen(set))
	{
		if (s1[end] == set[i])
		{
			end--;
			i = 0 ;
		}
		else
			i++;
	}
	return (end);
}

int	s_trim(char const *s1, char const *set)
{
	size_t	start;
	size_t	i;

	i = 0;
	start = 0;
	while (i < ft_strlen(set))
	{
		if (s1[start] == set[i])
		{
			start++;
			i = 0;
		}
		else
			i++;
	}
	return (start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		end;
	int		start;

	while (!s1)
		return (0);
	end = e_trim(s1, set);
	start = s_trim(s1, set);
	str = (char *)malloc(sizeof(char) * (end - start));
	if (!str)
		return (0);
	i = 0;
	while (i < end - start)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}
