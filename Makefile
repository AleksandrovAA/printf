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

SRC_NAME = ft_printf \

FUNCS_1 = ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memccpy \
		ft_memmove \
		ft_memcmp \
		ft_memchr \
		ft_strlen \
		ft_strdup \
		ft_strcpy \
		ft_strncpy \
		ft_strcat \
		ft_strncat \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strstr \
		ft_strnstr \
		ft_strcmp \
		ft_strncmp \
		ft_atoi \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower


FUNCS_2 = \
        ft_memalloc \
		ft_memdel \
		ft_strnew \
		ft_strdel \
		ft_striter \
		ft_striteri \
		ft_strmap \
		ft_strmapi \
		ft_strequ \
		ft_strnequ \
		ft_strsub \
		ft_strjoin \
		ft_strtrim \
		ft_strsplit \
		ft_itoa \
		ft_putchar \
		ft_putnbr \
		ft_putstr \
		ft_putendl \
		ft_putchar_fd \
		ft_putnbr_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_strclr
FUNCS_3	= \
        ft_lstnew \
        ft_lstdelone \
        ft_lstdel \
        ft_lstiter \
        ft_lstmap \
        ft_lstadd
MY_FUNCS = \
		ft_max \
		ft_min \
		ft_random \
		ft_strsave \
		ft_sqrt \
		ft_lltoa \
		ft_uitoa_base \
		ft_ulltoa_base \

ALL_FUNCS = $(FUNCS_1) $(FUNCS_2) $(FUNCS_3) $(MY_FUNCS)

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
