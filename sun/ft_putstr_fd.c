/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunahn <sunahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:49:46 by sunahn            #+#    #+#             */
/*   Updated: 2022/03/23 16:51:30 by sunahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	int	i;

	i = 0;
	while (*s)
	{
		write(fd, ft_putchar(*s), 1);
		s++;
	}
}
