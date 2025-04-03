# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meowy <meowy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 16:34:14 by meowy             #+#    #+#              #
#    Updated: 2025/04/02 18:36:59 by meowy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall #-Wextra -Werror# -g
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

NAME = push_swap

DEP = push_swap.h

all : $(NAME)

%.o: %.c $(DEP)
	$(CC) -c $(CFLAGS) $< -o $@
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY:
	all clean fclean re