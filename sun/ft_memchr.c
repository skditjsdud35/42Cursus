/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunahn <sunahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:57:19 by sunahn            #+#    #+#             */
/*   Updated: 2022/03/24 15:03:12 by sunahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void *ft_memchr(const void *s ,int c, size_t n)
{
	unsigned char *us;
	unsigned char uc;
	size_t	i;

	i = 0;
	us = (unsigned char *)s;
	uc = (unsigned char)c;
	while (i++ < n)
	{
		if (us[i] == uc)
			return ((void *)us + i);
	}
	return (0);
}
