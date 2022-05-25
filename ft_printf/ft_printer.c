/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunahn <sunahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:05:38 by sunahn            #+#    #+#             */
/*   Updated: 2022/05/15 16:05:23 by sunahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_num(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		len += 11;
		return (len);
	}
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		len += print_num(n / 10);
		len += print_num(n % 10);
	}
	if (n < 10)
		len += ft_putchar(n + 48);
	return (len);
}

int	print_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		len += ft_putchar(*str);
		str++;
	}
	return (len);
}

int	print_adr(unsigned long long n)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += print_adr(n / 16);
		len += print_adr(n % 16);
	}
	if (n < 16)
	{
		if (n < 10)
			len += ft_putchar(n + 48);
		else
			len += ft_putchar(n + 87);
	}
	return (len);
}

int	print_hex(unsigned int n, char c)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += print_hex(n / 16, c);
		len += print_hex(n % 16, c);
	}
	if (n < 16)
	{
		if (n < 10)
			len += ft_putchar(n + 48);
		else
		{
			if (c == 'x')
				len += ft_putchar(n + 87);
			else
				len += ft_putchar(n + 55);
		}
	}
	return (len);
}

int	print_unb(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += print_unb(n / 10);
		len += print_unb(n % 10);
	}
	if (n < 10)
		len += ft_putchar(n + 48);
	return (len);
}
