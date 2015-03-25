# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchampot <nchampot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/05 19:37:22 by nchampot          #+#    #+#              #
#    Updated: 2015/03/23 17:56:30 by nchampot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = draw.c main.c hook.c vector1.c vector2.c scene.c sphere.c ray.c

NAME = rtv1

all : $(NAME)

$(NAME) :
	@make re -C libft/
	@clang -Wall -Werror -Wextra $(SRC) libft/libft.a -lmlx -framework AppKit -framework OpenGL -o $(NAME)
	@echo rtv1 made successfully

clean :
	@rm -f $(NAME)

re : clean all

test : re
	@./$(NAME)
	@make clean

norm :
	@norminette --CheckForbiddenSourceHeader libft/ $(SRC) rtv1.h
