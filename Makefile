# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/08 17:26:44 by nsabbah           #+#    #+#              #
#    Updated: 2017/02/23 17:27:05 by nsabbah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c pipe.c room.c bfs_algo.c read.c debug.c

OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = ./libft/libft.a
LIBINC = -I./libft
LIBLINK = -L./libft -lft

SRCDIR = ./src/
INCDIR = ./includes/
OBJDIR = ./obj/

all: $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME): obj libft $(OBJ)
	$(CC) $(CFLAGS) $(LIBLINK) -o $(NAME) $(OBJ)

remlib:
	rm -rf $(LIBFT)

remoblib:
	make fclean -C ./libft/

clean: remoblib
	rm -rf $(OBJDIR)

fclean: clean remlib
	rm -rf $(NAME)

re: fclean all
