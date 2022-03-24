/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunahn <sunahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:50:19 by sunahn            #+#    #+#             */
/*   Updated: 2022/03/23 16:51:34 by sunahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n);
{
		unsigned char *us1;
		unsigned char *us2;
		size_t	i;

		us1 = (unsigned char *)s1;
		us2 = (unsigned char *)s2;
		i = 0;
		while (n-- > 0)
		{
			if (p1[i] != p2[i] || p1[i] == 0 || p2[i] == 0)
				return (p1[i] - p2[i]);
			i++;
		}
		return (0);
}
