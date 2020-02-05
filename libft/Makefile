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
		
MY_FUNCS = \
		ft_max \
		ft_min \
        ft_memset \
        ft_atoi \
        ft_bzero \
        ft_putchar \
        ft_putstr \
        ft_strlen \
        ft_strchr \
        ft_strchri \
		ft_lltoa \
		ft_uitoa_base \
		ft_ulltoa_base \


ALL_FUNCS = $(MY_FUNCS)
NAME = libft.a
SRC = $(addprefix $(SRC_PATH), $(addsuffix .c, $(ALL_FUNCS)))
OBJS = $(addsuffix .o, $(ALL_FUNCS))
SRC_PATH = ./
INCLUDE_PATH = ./
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_PATH)

all: $(NAME)

$(OBJS): %.o: %.c
	gcc -c $(CFLAGS) $^

$(NAME): $(OBJS)
	ar rc $(NAME) $?
	ranlib $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
