# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 14:38:58 by donshin           #+#    #+#              #
#    Updated: 2022/01/14 20:43:37 by donshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft/libft.a

CC = gcc
CFLAG = -Wall -Werror -Wextra

SRCS = \
	ft_printf.c \
	is_valid_format.c \
	parse_conversion.c \
	print_arg.c \
	print_char.c \
	print_nbr.c \
	print_string.c

OBJS = $(SRCS:.c=.o)


$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	mv $(LIBFT) $(NAME)
	ar rcus $@ $^

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
