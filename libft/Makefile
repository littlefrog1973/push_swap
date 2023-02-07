# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 11:08:07 by sdeeyien          #+#    #+#              #
#    Updated: 2023/02/06 10:24:03 by sdeeyien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

SRC = ./ft_isspace.c \
      ./ft_isalpha.c \
      ./ft_isdigit.c \
      ./ft_isalnum.c \
      ./ft_isascii.c \
      ./ft_toupper.c \
      ./ft_tolower.c \
      ./ft_isprint.c \
      ./ft_strlen.c \
      ./ft_memset.c \
      ./ft_bzero.c \
      ./ft_memcpy.c \
      ./ft_memmove.c \
      ./ft_strlcpy.c \
      ./ft_strlcat.c \
      ./ft_strchr.c \
      ./ft_strrchr.c \
      ./ft_strncmp.c \
      ./ft_memchr.c \
      ./ft_memcmp.c \
      ./ft_strdup.c \
      ./ft_calloc.c \
      ./ft_strnstr.c \
      ./ft_atoi.c \
      ./ft_substr.c \
      ./ft_strjoin.c \
      ./ft_strtrim.c \
      ./ft_split.c \
      ./ft_itoa.c \
      ./ft_strmapi.c \
      ./ft_striteri.c \
      ./ft_putchar_fd.c \
      ./ft_putstr_fd.c \
      ./ft_putendl_fd.c \
      ./ft_putnbr_fd.c \
      ./get_next_line.c \
      ./get_next_line_utils.c \
      ./ft_printf.c \
      ./putchr.c \
      ./puthex.c \
      ./putnbr.c \
      ./putptr.c \
      ./putstr.c \
      ./putunbr.c \
      ./ft_lstnew.c \
      ./ft_lstadd_front.c \
	./ft_lstsize.c \
	./ft_lstlast.c \
	./ft_lstadd_back.c \
	./ft_lstdelone.c \
	./ft_lstclear.c \
	./ft_lstiter.c \
	./ft_lstmap.c

OBJ = $(SRC:.c=.o)
NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar -crs $(NAME) $(OBJ)

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) $(SRC)

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
