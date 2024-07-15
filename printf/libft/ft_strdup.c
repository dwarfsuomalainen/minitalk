/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:51:37 by rbogoudi          #+#    #+#             */
/*   Updated: 2023/12/06 10:39:49 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	lensrc;
	char	*s2;
	char	*dest;

	lensrc = 0;
	while (s1[lensrc])
		lensrc++;
	s2 = malloc(sizeof(char) * (lensrc + 1));
	dest = s2;
	if (s2 == NULL)
		return (NULL);
	while (*s1)
	{
		*s2++ = *s1++;
	}
	*s2 = '\0';
	return (dest);
}
