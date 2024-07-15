/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:57:49 by rbogoudi          #+#    #+#             */
/*   Updated: 2023/12/06 10:52:54 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*processed;

	index = 0;
	if (s == 0 || f == 0)
		return (NULL);
	processed = ft_strdup(s);
	if (!processed)
		return (NULL);
	while (processed[index])
	{
		processed[index] = f(index, processed[index]);
		index++;
	}
	return (processed);
}
