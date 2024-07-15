/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:53:39 by rbogoudi          #+#    #+#             */
/*   Updated: 2023/12/06 10:40:05 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	int		i;
	int		k;
	char	*newstring;

	i = 0;
	k = 0;
	mem = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!mem)
		return (NULL);
	newstring = mem;
	while (ft_strlen(s1) > i)
	{
		newstring[i] = s1[i];
		i++;
	}
	while (ft_strlen(s2) > k)
	{
		newstring[i] = s2[k];
		i++;
		k++;
	}
	newstring[i] = '\0';
	return (newstring);
}
