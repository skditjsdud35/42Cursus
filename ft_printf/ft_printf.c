/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunahn <sunahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:05:47 by sunahn            #+#    #+#             */
/*   Updated: 2022/05/14 22:14:19 by sunahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	type_checker(char c, va_list *ap)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(*ap, int));
	else if (c == 'd' || c == 'i')
		len += print_num(va_arg(*ap, int));
	else if (c == 'u')
		len += print_unb(va_arg(*ap, unsigned int));
	else if (c == 's')
		len += print_str(va_arg(*ap, char *));
	else if (c == 'x')
		len += print_hex(va_arg(*ap, unsigned int), 'x');
	else if (c == 'X')
		len += print_hex(va_arg(*ap, unsigned int), 'X');
	else if (c == 'p')
	{
		len += write(1, "0x", 2);
		len += print_adr(va_arg(*ap, unsigned long int));
	}
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int			len;
	va_list		ap;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 0)
				break ;
			len += type_checker(*format, &ap);
		}
		else
		{
			len += ft_putchar(*format);
		}
		format++;
	}
	va_end(ap);
	return (len);
}
