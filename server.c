/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:15:11 by rbogoudi          #+#    #+#             */
/*   Updated: 2024/07/19 12:26:54 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*string_add(char const *s1, char const letter)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!tab)
		return (NULL);
	while (s1[i])
	{
		tab[j++] = s1[i++];
	}
	i = 0;
	tab[j++] = letter;
	tab[j] = 0;
	free((void *)(s1));
	return (tab);
}

void	print_and_free(char **string)
{
	ft_printf("%s\n", *string);
	free(*string);
	*string = NULL;
}

void	signal_handler(int sig)
{
	static int	bit_position = 0;
	static int	char_value = 0;
	static char	*string;

	if (!string)
		string = ft_strdup("");
	if (sig == SIGUSR2)
		char_value = ((char_value << 1) | 1);
	else if (sig == SIGUSR1)
		char_value = (char_value << 1);
	bit_position++;
	if (bit_position == 8)
	{
		string = string_add(string, char_value);
		if (char_value == '\0')
			print_and_free(&string);
		bit_position = 0;
		char_value = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server P I D --> %d\n", getpid());
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
