# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpythago <fpythago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/27 15:54:57 by lcarmelo          #+#    #+#              #
#    Updated: 2020/02/19 17:45:44 by fpythago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FUN_NAME = \
		ft_printf \
		handle_numbers \
		parse \
		buffer \
		round_numbers \
		handle_specifier

DIR_SRC		= ./src/
DIR_INC		= ./includes/
DIR_LIB		= ./libft/
OUTPUT      = ./a.out

SRC_PRINTF 	= $(addprefix $(DIR_SRC), $(addsuffix .c, $(FUN_NAME)))
OBJ_PRINTF 	= $(addsuffix .o, $(FUN_NAME))

CC 	   		= gcc
NAME 		= libftprintf.a
CFLAGS 	   	= -Wall -Werror -Wextra -O2 -I$(DIR_INC) -I$(DIR_LIB)$(DIR_INC)

all: $(NAME)

$(NAME):
	@make -C $(DIR_LIB)
	@cp libft/libft.a ./$(NAME)
	@$(CC) -c $(CFLAGS) $(SRC_PRINTF)
	@ar rc $(NAME) $(OBJ_PRINTF)
	@ranlib $(NAME)
    @gcc $(CFLAGS) src/main.c $(NAME)

clean:
	@make clean -C $(DIR_LIB)
	@rm -f $(OBJ_PRINTF)

fclean: clean
	@make fclean -C $(DIR_LIB)
	@rm -f $(NAME)
	@rm -f $(OUTPUT)

re: fclean all

.PHONY: all clean fclean re
