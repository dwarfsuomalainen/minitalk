/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:55:49 by rbogoudi          #+#    #+#             */
/*   Updated: 2023/12/06 10:52:42 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenword(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static	int	ft_countword(char const *s, char c)
{
	int	words;
	int	wordlen;

	words = 0;
	while (*s)
	{
		wordlen = ft_lenword(s, c);
		if (wordlen != 0)
		{
			words++;
			s += wordlen;
		}
		else
			s++;
	}
	return (words);
}

static char	*ft_freearr(char **arr, int n)
{
	int	i;

	i = n;
	while (i > 0)
		free(arr[--i]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		words;
	int		wordlen;

	i = 0;
	words = ft_countword(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (arr == NULL)
		return (NULL);
	while (i < words)
	{
		wordlen = ft_lenword(s, c);
		if (wordlen != 0)
		{
			arr[i] = ft_substr(s, 0, wordlen);
			if (arr[i] == NULL)
				return ((char **) ft_freearr (arr, i));
			i++;
		}
		s += (wordlen + 1);
	}
	arr[i] = NULL;
	return (arr);
}
