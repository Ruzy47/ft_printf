# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 17:35:50 by rugrigor          #+#    #+#              #
#    Updated: 2023/02/06 19:33:02 by rugrigor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =libftprintf.a

CC =cc

CFLAGS= -Wall -Wextra -Werror

SRCS =  ft_printf.c		\
		ft_numbers.c	\
		funcs.c			\

OBJS        = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@ar r $(NAME) $(OBJS)

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf $(OBJS)

re: fclean all

.PHONY: all clean fclean re
