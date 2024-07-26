# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/09 13:32:21 by rbogoudi          #+#    #+#              #
#    Updated: 2024/07/19 12:03:02 by rbogoudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a

SOURCES = 	ft_print_char.c \
			ft_print_string.c \
			ft_print_digit.c \
			ft_print_digit_hex.c \
			ft_print_pointer.c \
			ft_print_percent.c \
			ft_print_digit_unsigned.c \
			ft_printf.c

		
OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

HEADERS = ft_printf.h

CC = cc

.PHONY:
	all clean fclean re

all: $(NAME)

# Rule for building the target file
$(NAME): $(OBJECTS) 
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean: clean	
	$(MAKE) fclean -C
	rm -rf $(NAME)

re: fclean all


