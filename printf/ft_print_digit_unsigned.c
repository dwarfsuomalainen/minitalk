/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:19:06 by rbogoudi          #+#    #+#             */
/*   Updated: 2024/01/15 11:15:40 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_print_digit_unsigned(unsigned int n, int base)
{
	int		counter;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < (unsigned int)base)
	{
		return (ft_print_char(symbols[n]));
	}
	else
	{
		counter = ft_print_digit_unsigned(n / base, base);
		if (counter == -1)
			return (-1);
		return (counter + ft_print_digit_unsigned(n % base, base));
	}
}
