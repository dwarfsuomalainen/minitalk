/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:07:36 by rbogoudi          #+#    #+#             */
/*   Updated: 2024/01/15 11:13:12 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int	ft_maxmin(void)
{
	char	*maxmin;

	maxmin = "-2147483648";
	while (*maxmin)
	{
		if (ft_print_char(*maxmin) == -1)
			return (-1);
		maxmin++;
	}
	return (0);
}

int	ft_print_digit(int n, int base)
{
	int		counter;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n == INT_MIN)
	{
		if (ft_maxmin() == -1)
			return (-1);
		return (11);
	}
	else if (n < 0)
	{
		if (ft_print_char('-') == -1)
			return (-1);
		return (ft_print_digit(-n, base) + 1);
	}
	else if (n < base)
		return (ft_print_char(symbols[n]));
	else
	{
		counter = ft_print_digit(n / base, base);
		if (counter == -1)
			return (-1);
		return (counter + ft_print_digit(n % base, base));
	}
}
