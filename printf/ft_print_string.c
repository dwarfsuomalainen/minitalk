/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:06:02 by rbogoudi          #+#    #+#             */
/*   Updated: 2024/01/09 15:14:50 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	int		count;

	count = 0;
	if (str == NULL)
	{
		str = "(null)";
		while (*str)
		{
			if (ft_print_char((int)*str) < 0)
				return (-1);
			++count;
			++str;
		}
	}
	else
	{
		while (*str)
		{
			if (ft_print_char((int)*str) < 0)
				return (-1);
			++count;
			++str;
		}
	}
	return (count);
}
