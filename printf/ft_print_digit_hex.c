/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:00:42 by rbogoudi          #+#    #+#             */
/*   Updated: 2024/01/15 13:19:17 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_print_digit_hex(unsigned long n, int base, int specifier)
{
	int		counter;
	char	*symbols;

	if (specifier == 'x')
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789ABCDEF";
	if (n < (unsigned long)base)
	{
		return (ft_print_char(symbols[n]));
	}
	else
	{
		counter = ft_print_digit_hex(n / base, base, specifier);
		if (counter == -1)
			return (-1);
		return (counter + ft_print_digit_hex(n % base, base, specifier));
	}
}
