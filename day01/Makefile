# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihkang <jihkang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 06:26:35 by jihkang           #+#    #+#              #
#    Updated: 2022/08/16 07:44:48 by jihkang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRCS		= main.c \
			key_utils.c \
			ft_memset.c
OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		gcc -o $(NAME) $(OBJS) -L/usr/local/include/ -lmlx -framework OpenGL -framework Appkit

%.o			:	%.c
		gcc $(FLAGS) -c $^ -I./  -o $@
clean		:
		rm -f $(OBJS)

fclean		:	clean
		rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re