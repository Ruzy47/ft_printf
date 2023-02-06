# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 17:35:50 by rugrigor          #+#    #+#              #
#    Updated: 2023/02/06 17:41:46 by rugrigor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =libft.a

CC =cc

CFLAGS= -Wall -Wextra -Werror

SRCS =  $(wildcard *.c)

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
