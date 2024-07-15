# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/09 13:32:21 by rbogoudi          #+#    #+#              #
#    Updated: 2024/01/15 14:27:41 by rbogoudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

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

LIBFT = libft/libft.a

LIBFT_DIR = ./libft

CC = cc

.PHONY:
	all clean fclean re

all: $(NAME)


# Rule for building the target file
$(NAME): $(LIBFT) $(OBJECTS)
	cp $(LIBFT) $(NAME) 
	ar rcs $(NAME) $(OBJECTS)

# Rule for building libft
$(LIBFT) : $(LIBFT_DIR )
	$(MAKE) -C $(LIBFT_DIR:.c=.o)

clean:
	rm -rf $(OBJECTS)

fclean: clean	
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all


