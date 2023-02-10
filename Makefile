# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 12:25:01 by sdeeyien          #+#    #+#              #
#    Updated: 2023/02/10 00:39:37 by sdeeyien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
#CFLAGS =
UNAME_S := $(shell uname -s)
LIBDIR = ./libft/
LIBOBJ = libft.a
SRCDIR = ./src/
OBJDIR = ./obj/
DEPS = push_swap.h

SRC = check_argv.c utils.c sort.c sort_utils.c stack1.c stack2.c \
      stack3.c sort_algo.c main.c

SRC := $(addprefix $(SRCDIR), $(SRC))
DEPS := $(addprefix $(SRCDIR), $(DEPS))
OBJ = $(SRC:.c=.o)

NAME = push_swap

all : $(NAME)

$(NAME): $(SRC)
	cd $(LIBDIR) && make
	$(CC) $(CFLAGS) $(DEPS) $(SRC) $(LIBDIR)/$(LIBOBJ) -o $(NAME)
#	$(CC) $(CFLAGS) $(addprefix $(SRCDIR), $(SRC)) $(addprefix $(SRCDIR), $(DEPS)) $(LIBDIR)/$(LIBDIR).a -o $(NAME)

clean :
	rm -f $(SRCDIR)/*.o
	make -C $(LIBDIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBDIR) fclean

re : fclean all

.PHONY : all clean fclean re bonus
