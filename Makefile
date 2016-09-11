# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/27 01:48:43 by ahamouda          #+#    #+#              #
#    Updated: 2016/09/11 18:41:00 by ahamouda         ###   ########.fr        #
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

HEADER_FILE = libftprintf.h

HEADER = $(HEADER_FILE:%.h=$(HEADER_PATH)/%.h)

LIB = ./libftprintf/libftprintf.a

## Objects/Sources.


OBJ_PATH = Objects
OBJECTS = $(addprefix $(OBJ_PATH)/, $(SOURCES:%.c=%.o))

SRC_PATH = Sources
SRC_SUBDIR += Error
SRC_SUBDIR += Maths
SRC_SUBDIR += Memory
SRC_SUBDIR += Std_lib
SRC_SUBDIR += String
SRC_SUBDIR += Write

vpath %.c $(addprefix $(SRC_PATH)/,$(SRC_SUBDIR))

# STD_LIB

SRC += ft_atoi.c
SRC += ft_itoa.c

# MEMORY

SRC += byte_swap.c
SRC += ft_bzero.c
SRC += ft_memalloc.c
SRC += ft_memchr.c
SRC += ft_memcpy.c
SRC += ft_memmove.c
SRC += ft_memset.c

# STRING

SRC += ft_strcmp.c
SRC += ft_strcpy.c
SRC += ft_strdup.c
SRC += ft_strlen.c

# ERROR

SRC += leave_error.c
SRC += malloc_error.c

# MATHS

SRC += fctrl.c

# WRITE

SRC += ft_putendl.c
SRC += ft_putstr.c

NORMINETTE_TEST := $(shell norminette $(SRC) $(HEADER) | grep -B 1 Error)

#.SILENT:

all : $(NAME)

$(NAME) : $(OBJECTS) $(HEADER)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJECTS): $(HEADERS) | $(OBJ_PATH)

$(OBJECTS): $(OBJ_PATH)/%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) $(SFLAGS) -I $(HEADER_PATH)

$(OBJ_PATH):
	@-mkdir -p $@

clean:
	$(RM) -r $(OBJ_PATH)

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
