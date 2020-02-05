# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/27 15:54:57 by lcarmelo          #+#    #+#              #
#    Updated: 2019/09/27 15:55:04 by lcarmelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = ./src/
INC_DIR = ./includes/
LIB_DIR = ./libft/

SRC_NAME = \
            ft_printf \
            print_str \
            print_nbr \
            specifiers \

MY_FUNCS = \
        ft_atoi \
        ft_bzero \
        ft_isdigit \
        ft_itoa \
        ft_putchar \
        ft_putstr \
        ft_putnbr \
        ft_strchr \
        ft_strchri \
        ft_strlen \
        ft_memset \
		ft_max \
		ft_min \
		ft_lltoa \
		ft_uitoa_base \
		ft_ulltoa_base \

ALL_FUNCS = $(MY_FUNCS)

SRCSLIB = $(addprefix $(LIB_DIR), $(addsuffix .c, $(ALL_FUNCS)))

SRCSPRINTF = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_NAME)))

OBJLIB = $(addsuffix .o, $(ALL_FUNCS))

OBJPRINTF = $(addsuffix .o, $(SRC_NAME))

ALLOBJS = $(OBJLIB)  $(OBJPRINTF)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIB_DIR)

all: $(NAME)

$(ALLOBJS):
	$(CC) $(CFLAGS) -c $(SRCSLIB) $(SRCSPRINTF) 

$(NAME): $(ALLOBJS)
	ar rc $(NAME) $?
	ranlib $(NAME)
	rm -f $(ALLOBJS)
	gcc ./src/main.c libftprintf.a -I $(LIB_DIR) -I $(INC_DIR)

clean:
	rm -f $(ALLOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
