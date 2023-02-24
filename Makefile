# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 12:25:01 by sdeeyien          #+#    #+#              #
#    Updated: 2023/02/24 10:51:38 by sdeeyien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Werror -Wextra
#CFLAGS =
UNAME_S := $(shell uname -s)
LIBDIR = ./libft/
LIBOBJ = libft.a
SRCDIR = ./src/
OBJDIR =
DEPS = push_swap.h

SRC = check_argv.c utils.c sort.c sort_utils.c sort_utils2.c stack1.c stack2.c \
      stack3.c sort_algo.c sort_algo2.c sort_algo3.c sort_algo4.c push_swap.c \
      sort_algo5.c sort_algo6.c sort_algo6_a.c utils2.c sort_algo7.c
BONUS = checker.c check_argv_bonus.c check_sort_bonus.c stack1_bonus.c \
        stack2_bonus.c stack3_bonus.c utils_bonus.c sort_utils_bonus.c \
        utils2_bonus.c

OBJ := $(patsubst %.c, $(OBJDIR)%.o, $(SRC))
BONUS_OBJ := $(patsubst %.c, $(OBJDIR)%.o, $(BONUS))
SRC := $(addprefix $(SRCDIR), $(SRC))
BONUS := $(addprefix $(SRCDIR), $(BONUS))
DEPS := $(addprefix $(SRCDIR), $(DEPS))

NAME = push_swap
BONUS_NAME = checker

all : $(NAME) $(BONUS_NAME)

$(NAME): $(OBJ)
	make -C $(LIBDIR) all
	$(CC) $(CFLAGS) $^ $(LIBDIR)/$(LIBOBJ) -o $@

bonus : $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	make -C $(LIBDIR) all
	$(CC) $(CFLAGS) $^ $(LIBDIR)/$(LIBOBJ) -o $@

%.o: $(SRCDIR)%.c $(DEPS)
	$(CC) -c $(CFLAGS) $(DEPS) $<


clean :
	rm -f *.o
	make -C $(LIBDIR) clean

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C $(LIBDIR) fclean

re : fclean all

.PHONY : all clean fclean re bonus
