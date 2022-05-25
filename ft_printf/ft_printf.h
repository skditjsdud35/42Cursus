/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunahn <sunahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:50:14 by sunahn            #+#    #+#             */
/*   Updated: 2022/05/15 16:13:16 by sunahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	print_num(int n);
int	print_str(char *str);
int	print_adr(unsigned long long n);
int	print_hex(unsigned int n, char c);
int	print_unb(unsigned int n);
int	ft_putchar(char c);
int	type_checker(char c, va_list *ap);
int	ft_printf(const char *format, ...);

#endif
