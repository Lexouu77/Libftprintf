# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/27 01:48:43 by ahamouda          #+#    #+#              #
#    Updated: 2016/09/09 15:55:24 by ahamouda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Basics.

NAME = libftprintf.a

CC = clang

RM = rm -f

## Flags.

CFLAGS = -Wall -Werror -Wextra

SFLAGS = -Weverything

OFLAGS = -O3 -march=native

DFLAGS = -g3 -fsanitize=address

## Lib/Header.

HEADER_PATH = ./includes

HEADER = libftprintf.h

HEADERS = $(HEADER:%.h=$(HEADER_PATH)/%.h)

LIB = ./libftprintf/libftprintf.a

## Objects/Sources.

OBJ = $(SRC:.c=.o)

SRC = byte_swap.c\
	  fctrl.c\
	  ft_atoi.c\
	  ft_bzero.c\
	  ft_itoa.c\
	  ft_memalloc.c\
	  ft_memchr.c\
	  ft_memcpy.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_putendl.c\
	  ft_putstr.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strdup.c\
	  leave_error.c\
	  malloc_error.c

SRC_PATH =

NORMINETTE_TEST := $(shell norminette $(SRC) $(HEADERS) | grep -B 1 Error)

#.SILENT:

all : $(NAME)

$(NAME) : $(OBJ) $(HEADERS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) $(SFLAGS) -I $(HEADER_PATH)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norme:
ifeq ($(NORMINETTE_TEST), )
	@echo "Everything ok!"
else
	@norminette $(SRC) $(HEADERS) | grep -B 1 Error
endif

watch:
	watch "make norme" "20"

function:
	nm -u $(NAME)

.PHONY: re fclean clean all norme watch function
