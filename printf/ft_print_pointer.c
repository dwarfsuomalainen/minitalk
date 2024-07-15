/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:09:52 by rbogoudi          #+#    #+#             */
/*   Updated: 2024/01/15 13:14:01 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(unsigned long n, int base)
{
	char	*str;

	str = "0x";
	if (ft_print_string(str) == -1)
		return (-1);
	return (ft_print_digit_hex(n, base, 'x') + 2);
}
