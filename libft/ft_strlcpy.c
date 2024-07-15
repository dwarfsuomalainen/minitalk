/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:42:18 by rbogoudi          #+#    #+#             */
/*   Updated: 2023/12/06 10:40:14 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = dst;
	s = src;
	if (dstsize == 0)
	{
		return (ft_strlen(src));
	}
	while (*s && i < dstsize - 1)
	{
		*d++ = *s++;
		i++;
	}
	*d = '\0';
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}
