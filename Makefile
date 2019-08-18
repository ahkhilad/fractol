# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 14:38:16 by ahkhilad          #+#    #+#              #
#    Updated: 2019/08/08 21:52:58 by ahkhilad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LFT = libft/libft.a

SRCS = ./srcs/main.c ./srcs/mandelbrot.c ./srcs/julia.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

EXEC = gcc $(CFLAGS) -lmlx -framework OpenGL -framework AppKit

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(OBJ): $(SRCS)
	@echo "\033[2;33m"
	gcc -c $(SRCS) -I fractol.h
	mv *.o ./srcs/
	@echo "\033[0m"

$(LFT): libft/*.c
	@echo "\033[2;33m"
	make -C libft
	@echo "\033[0m"

$(NAME): $(OBJ) $(LFT)
	@echo "\033[2;33m"
	$(EXEC) $^ -o $@
	@echo "\033[0m"
	@echo "\033[3;32m\t\t\t\t\tAll Set !\n\033[0m"

clean:
	@echo "\033[2;31m"
	make -C libft clean
	rm -rf $(OBJ)
	@echo "\033[0m"
	@echo "\033[4;31mObject Files Deleted\033[0m"

fclean: clean
	@echo "\033[2;31m"
	make -C libft fclean
	rm -rf $(NAME)
	@echo "\033[0m"
	@echo "\033[4;31mBinary File Deleted\n\033[0m"

re: fclean all
