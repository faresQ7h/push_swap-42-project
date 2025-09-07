# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/04 21:23:18 by farmoham          #+#    #+#              #
#    Updated: 2025/09/07 17:49:27 by farmoham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = main.c movments.c stack_operations.c valid_arguments.c sorting.c continue_sorting.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = cc
LIBFT_DIR = libftprintf
LIBFT_EXE = $(LIBFT_DIR)/libftprintf.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):$(OBJ) $(LIBFT_EXE)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_EXE) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT_EXE):
	$(MAKE) -C libftprintf

clean:
	rm -f *.o
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f *.o
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
