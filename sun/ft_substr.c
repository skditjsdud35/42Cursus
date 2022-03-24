/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunahn <sunahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:02:45 by sunahn            #+#    #+#             */
/*   Updated: 2022/03/23 18:12:22 by sunahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
//#include "libft.h"
#include <stdlib.h>
#include <string.h>
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1)))
			|| !s || start >= (unsigned int)ft_strlen(s))
		return (0);
	while (len-- > 0)
	{
		result[i] = s[start];
		i++;
		start++;
	}
	result[i] = 0;
	return (result);
}
int main()
{
	printf("%s\n", ft_substr("abcd",5,3));
}
