# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 12:25:01 by sdeeyien          #+#    #+#              #
#    Updated: 2023/02/07 08:56:23 by sdeeyien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
#CFLAGS =
UNAME_S := $(shell uname -s)
LIBDIR = ./libft
SRCDIR = ./src/
OBJDIR = ./obj/
DEPS = push_swap.h

SRC = check_argv.c main.c utils.c
SRC := $(addprefix $(SRCDIR), $(SRC))
OBJ = $(SRC:.c=.o)

NAME = push_swap

all : $(NAME)

$(NAME): $(SRC)
#$(NAME): ./src/check_argv.c ./src/main.c ./src/utils.c
	cd $(LIBDIR) && make
	$(CC) $(CFLAGS) $(SRC) $(addprefix $(SRCDIR), $(DEPS)) $(LIBDIR)/$(LIBDIR).a -o $(NAME)
#	$(CC) $(CFLAGS) $(addprefix $(SRCDIR), $(SRC)) $(addprefix $(SRCDIR), $(DEPS)) $(LIBDIR)/$(LIBDIR).a -o $(NAME)

clean :
	rm -f $(SRCDIR)/*.o
	make -C $(LIBDIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBDIR) fclean

re : fclean all

.PHONY : all clean fclean re bonus
