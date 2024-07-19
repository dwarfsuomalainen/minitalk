/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:41:21 by rbogoudi          #+#    #+#             */
/*   Updated: 2024/07/19 11:48:09 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

int		ft_print_char(int c);
int		ft_print_string(char *str);
int		ft_print_digit(int n, int base);
int		ft_print_digit_hex(unsigned long n, int base, int specifier);
int		ft_print_pointer(unsigned long n, int base);
int		ft_print_digit_unsigned(unsigned int n, int base);
int		ft_printf(const char *c, ...);

#endif