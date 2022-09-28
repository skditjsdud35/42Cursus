/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:55:28 by donshin           #+#    #+#             */
/*   Updated: 2022/01/13 11:13:03 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg(char type, va_list ap, int *byte)
{
	if (ft_strchr("c", type))
		print_char((char)va_arg(ap, int), byte);
	else if (ft_strchr("s", type))
		print_string(va_arg(ap, char *), byte);
	else if (ft_strchr("p", type))
		print_nbr(type, va_arg(ap, unsigned long), byte);
	else if (ft_strchr("di", type))
		print_nbr(type, va_arg(ap, int), byte);
	else if (ft_strchr("uxX", type))
		print_nbr(type, va_arg(ap, unsigned int), byte);
	else if (ft_strchr("%", type))
		print_char('%', byte);
}
