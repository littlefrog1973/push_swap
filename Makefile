# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 12:25:01 by sdeeyien          #+#    #+#              #
#    Updated: 2023/02/16 12:47:32 by sdeeyien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
#CFLAGS =
UNAME_S := $(shell uname -s)
LIBDIR = ./libft/
LIBOBJ = libft.a
SRCDIR = ./src/
OBJDIR = ./obj/
DEPS = push_swap.h

SRC = check_argv.c utils.c sort.c sort_utils.c sort_utils2.c stack1.c stack2.c \
      stack3.c sort_algo.c sort_algo2.c sort_algo3.c sort_algo4.c push_swap.c
BONUS = checker.c check_argv.c check_sort.c stack1.c stack2.c stack3.c utils.c \
      sort_utils.c sort.c sort_algo.c sort_algo2.c sort_algo3.c sort_algo4.c

OBJ := $(SRC:.c=.o)
BONUS_OBJ := $(BONUS:.c=.o)
SRC := $(addprefix $(SRCDIR), $(SRC))
BONUS := $(addprefix $(SRCDIR), $(BONUS))
DEPS := $(addprefix $(SRCDIR), $(DEPS))

NAME = push_swap

all : $(NAME)

$(NAME): $(OBJ)
	cd $(LIBDIR) && make
	$(CC) $(CFLAGS) $(DEPS) $(OBJ) $(LIBDIR)/$(LIBOBJ) -o $(NAME)
#	$(CC) $(CFLAGS) $(DEPS) $(SRC) $(LIBDIR)/$(LIBOBJ) -o $(NAME)
#	$(CC) $(CFLAGS) $(addprefix $(SRCDIR), $(SRC)) $(addprefix $(SRCDIR), $(DEPS)) $(LIBDIR)/$(LIBDIR).a -o $(NAME)

bonus: $(BONUS_OBJ)
	cd $(LIBDIR) && make
	$(CC) $(CFLAGS) $(DEPS) $(BONUS_OBJ) $(LIBDIR)/$(LIBOBJ) -o checker

$(OBJ): $(SRC)
	$(CC) -c -g $(CFLAGS) $(DEPS) $(SRC)

$(BONUS_OBJ): $(BONUS)
	$(CC) -c -g $(CFLAGS) $(DEPS) $(BONUS)
clean :
	rm -f *.o
	make -C $(LIBDIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBDIR) fclean

re : fclean all

.PHONY : all clean fclean re bonus
