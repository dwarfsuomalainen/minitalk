/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:56:41 by rbogoudi          #+#    #+#             */
/*   Updated: 2023/12/06 10:51:55 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n)
{
	int	intlen;

	intlen = 0;
	if (n == 0)
		n = 1;
	if (n < 0)
	{
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		intlen++;
	}
	return (intlen);
}

int	ft_isneg(int i)
{
	if (i < 0)
		return (i = 1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		isneg;
	int		index;

	isneg = ft_isneg(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num = (char *)malloc(sizeof(char) * (ft_intlen(n) + (isneg + 1)));
	if (!num)
		return (NULL);
	index = (ft_intlen(n) + isneg) - 1;
	num[index + 1] = '\0';
	if (isneg != 0)
	{
		num[0] = '-';
		n = -n;
	}
	while (index >= 0 && n != 0)
	{
		num[index--] = '0' + (n % 10);
		n /= 10;
	}
	return (num);
}
