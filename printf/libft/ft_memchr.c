/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:35:13 by rbogoudi          #+#    #+#             */
/*   Updated: 2023/12/06 10:38:21 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		unc;

	str = s;
	unc = (unsigned char)c;
	while (n--)
	{
		if (*str != unc)
			str++;
		else
			return ((void *)str);
	}
	return (NULL);
}
