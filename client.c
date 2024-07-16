/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:42:56 by rbogoudi          #+#    #+#             */
/*   Updated: 2024/07/16 12:30:20 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void err_msg_exit(int error_code)
{
	if (error_code == 1)
		ft_printf("[+] Error: \033[31mNo server_id\n\033[0m \n");
	if (error_code == 2)
		ft_printf("[+] Error: \033[31mNo string provided\n\033[0m \n");
	if (error_code == 3)
		ft_printf("[+] Error: \033[31mWrong P I D\n\033[0m \n");
	if (error_code == 4)
		ft_printf("[+] Error: \033[31mNo message recieved\n\033[0m \n");
	if (error_code == 5)
		ft_printf("[+] Error: \033[31mPlease use a format :\n\
		./client<P I D Server> <\"STRING\">\n\033[0m \n");
	if (error_code == 6)
		ft_printf("[+] Error: \033[31mKill signal failed\n\033[0m \n");
	exit (0);
}

void broadcast(int pid,char *string)
{
	int	string_position;
	int	bit_position;

	string_position = 0;
	while (string[string_position])
	{
		bit_position = -1;
		while (++bit_position < 8)
	{
		if (((unsigned char)(string[string_position] >> (7 - bit_position)) & 1)== 0)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(200);
	}
	string_position++;
	}
	
	
	bit_position = 0;
	while (bit_position++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(200);
	}
}

int main(int argc, char **argv)
{
    char	*string;
    int		server_id;

	if (argc == 3)
	{
		server_id = ft_atoi(argv[1]);
		if (!server_id)
			err_msg_exit(1);
		if (kill(server_id, 0) == -1)
			err_msg_exit(3);
		string = argv[2];
		if (string[0]== 0)
			err_msg_exit(2);
		broadcast(server_id, string);
	}
	else
		err_msg_exit(5);
	return (EXIT_SUCCESS);
}