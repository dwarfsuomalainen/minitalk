/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:44:15 by rbogoudi          #+#    #+#             */
/*   Updated: 2024/07/19 11:33:39 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_print_string(va_arg(ap, char *));
	else if (specifier == 'p')
		count += ft_print_pointer(va_arg(ap, unsigned long), 16);
	else if (specifier == 'd')
		count += ft_print_digit(va_arg(ap, int), 10);
	else if (specifier == 'i')
		count += ft_print_digit(va_arg(ap, int), 10);
	else if (specifier == 'u')
		count += ft_print_digit_unsigned(va_arg(ap, unsigned int), 10);
	else if (specifier == 'x')
		count += ft_print_digit_hex(va_arg(ap, unsigned int), 16, specifier);
	else if (specifier == 'X')
		count += ft_print_digit_hex(va_arg(ap, unsigned int), 16, specifier);
	else if (specifier == '%')
		count += ft_print_char('%');
	else
		count += ft_print_char(specifier);
	return (count);
}

int	ft_printf(const char *c, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, c);
	while (*c)
	{
		if (*c == '%')
		{
			count += ft_print_c(*(++c), ap);
			if (count < 0)
				return (-1);
		}
		else
		{
			count += ft_print_char(*c);
			if (count < 0)
				return (-1);
		}
		++c;
	}
	va_end(ap);
	return (count);
}
