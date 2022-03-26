/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunahn <sunahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:50:23 by sunahn            #+#    #+#             */
/*   Updated: 2022/03/26 18:15:52 by sunahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	hay_len;
	size_t	cnt;

	i = 0;
	cnt = 0;
	hay_len = ft_strlen(haystack);
	if (!needle)
		return (haystack);
	while (i < hay_len - len)
	{
		if (

}
