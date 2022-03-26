/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunahn <sunahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:06:06 by sunahn            #+#    #+#             */
/*   Updated: 2022/03/26 18:18:29 by sunahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
int	ft_get_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		minus;

	minus = 0;
	len = ft_get_len(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len--] = 0;
	if (n < 0)
	{
		minus = 1;
		n *= -1;
	}
	while (n != 0)
	{
		result[len--] = n % 10 + 48;
		n /= 10;
	}
	result[len] = n % 10 + 48;
	if (minus == 1)
		result[0] = '-';
	return (result);
}
