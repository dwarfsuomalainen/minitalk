/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:55:34 by rbogoudi          #+#    #+#             */
/*   Updated: 2023/12/06 10:38:51 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned long	index;
	unsigned char	p;
	char			*s;

	p = c;
	s = (char *) str;
	index = 0;
	while (index < n)
	{
		s[index] = p;
		index++;
	}
	return (str);
}
