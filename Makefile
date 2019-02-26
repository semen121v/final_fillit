# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fshade <fshade@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 17:06:20 by eschoen           #+#    #+#              #
#    Updated: 2019/02/26 22:01:56 by fshade           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fillit
FLAG = -Wall -Wextra -Werror
SRC = main.c fillit.c valid_tetriminos.c newlist.c map.c coordinates.c readfile.c newtetrimo.c size.c new_coordinates.c  resolve_fillit.c 
OBJ = $(SRC:.c=.o)
LIB = libft.a


all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	clang -o $(NAME) $(OBJ) -I./includes/ -I./libft/includes -L libft/ -lft

$(LIB):
	$(MAKE) -C libft/

%.o: %.c
	clang -Wall -Wextra -Werror -I./libft/includes -I./includes/ -o $@ -c $<
	
clean:
	@rm -f $(OBJ)
	$(MAKE) -C libft/ clean 

fclean: clean 
	@rm -f $(NAME)
	$(MAKE) -C libft/ fclean 

re: fclean all