cmake_minimum_required(VERSION 3.15)
project(printf C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
include_directories(libft)

add_executable(printf
        includes/ft_printf.h
        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_isdigit.c
        libft/ft_itoa.c
        libft/ft_lltoa.c
        libft/ft_max.c
        libft/ft_memset.c
        libft/ft_min.c
        libft/ft_putchar.c
        libft/ft_putnbr.c
        libft/ft_putstr.c
        libft/ft_strchr.c
        libft/ft_strchri.c
        libft/ft_strlen.c
        libft/ft_strndup.c
        libft/ft_uitoa_base.c
        libft/ft_ulltoa_base.c
        libft/libft.h
        src/floats.c
        src/ft_printf.c
        src/main.c
        src/print_nbr.c
        src/print_str.c
        src/specifiers.c)
