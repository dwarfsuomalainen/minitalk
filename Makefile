# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 11:52:26 by rbogoudi          #+#    #+#              #
#    Updated: 2024/07/19 14:18:45 by rbogoudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME = client

SERVER_NAME = server

C_SOURCE = client.c

S_SOURCE = server.c
			
C_OBJECT = $(C_SOURCE:.c=.o)

S_OBJECT = $(S_SOURCE:.c=.o)

LIBFT = libft/libft.a

PRINTF = printf/printf.a

all: $(CLIENT_NAME) $(SERVER_NAME)

%.o:%.c
	@cc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

$(CLIENT_NAME): $(C_OBJECT)
	@make -C libft
	@make -C printf
	@cc -Wall -Wextra -Werror $(C_OBJECT) $(LIBFT) $(PRINTF) -o $(CLIENT_NAME)
	@echo client has been created

$(SERVER_NAME): $(S_OBJECT)
	@make -C libft
	@make -C printf
	@cc -Wall -Wextra -Werror $(S_OBJECT) $(LIBFT) $(PRINTF) -o $(SERVER_NAME)
	@echo server has been created

clean:
	rm -f $(C_OBJECT)
	rm -f $(S_OBJECT)
	@make clean -C libft
	@make clean -C printf

fclean: clean
	@rm -f $(CLIENT_NAME)
	@rm -f $(SERVER_NAME)
	@rm -f libft/libft.a
	@rm -f printf/libftprintf.a

re: fclean all

.PHONY: clean fclean all re makelibft bonus