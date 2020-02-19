# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/27 15:54:57 by lcarmelo          #+#    #+#              #
#    Updated: 2020/02/11 21:04:08 by lcarmelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
		
FUN_CONVERSION = \
        ft_atoi \
		ft_lltoa \
		ft_uitoa_base \
		ft_ulltoa_base \

FUN_MEMORY = \
        ft_memset \
        ft_bzero \
        ft_memcpy \
        ft_memccpy \
        ft_memmove \
        ft_memchr \
        ft_memalloc \
        ft_memdel \
		ft_memswap \
		ft_swap

FUN_STRINGS = \
        ft_isprint \
        ft_isdigit \
        ft_putchar \
        ft_putstr \
        ft_strlen \
        ft_strchr \
		ft_strjoin \
		ft_strcpy \
		ft_strdup \
		ft_strcat \
        ft_strchri \
		ft_strclr

FUN_VECTOR = \
		vector_init \
		vector_copy \
		vector_move \
		vector_move_data \
		vector_move_back_data \
		vector_push_data \
		vector_push_back \
		vector_push_front \
		vector_insert \
		vector_get_element \
		vector_pop_back \
		vector_pop_front \
		vector_erase \
		vector_clear \
		vector_destroy \
		vector_is_empty \
		vector_byte_size \
		vector_free_size \
		vector_resize \
		vector_reallocate \
		vector_offset \

DIR_CONVERSION  = ./conversion/
DIR_MEMORY      = ./memory/
DIR_STRINGS     = ./strings/
DIR_VECTOR 		= ./vector/
DIR_INC   		= ./includes/

SRC_CONVERSION  = $(addprefix $(DIR_CONVERSION), $(addsuffix .c, $(FUN_CONVERSION)))
SRC_MEMORY      = $(addprefix $(DIR_MEMORY), $(addsuffix .c, $(FUN_MEMORY)))
SRC_STRINGS     = $(addprefix $(DIR_STRINGS), $(addsuffix .c, $(FUN_STRINGS)))
SRC_VECTOR 		= $(addprefix $(DIR_VECTOR), $(addsuffix .c, $(FUN_VECTOR)))

SRC_ALL         = $(SRC_CONVERSION) $(SRC_MEMORY) $(SRC_STRINGS) $(SRC_VECTOR)
OBJ_ALL         = $(addsuffix .o, $(FUN_CONVERSION) $(FUN_MEMORY) $(FUN_STRINGS) $(FUN_VECTOR))

CC              = gcc
NAME            = libft.a
CFLAGS          = -Wall -Wextra -Werror -O2 -I$(DIR_INC)

all: $(NAME)

$(OBJ_ALL):
	$(CC) -c $(CFLAGS) $(SRC_ALL) 

$(NAME): $(OBJ_ALL)
	@ar rc $(NAME) $?
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ_ALL)

fclean: clean
	@rm -f $(NAME)

re: fclean all
