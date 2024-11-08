# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 16:29:10 by asuteau           #+#    #+#              #
#    Updated: 2024/02/28 09:07:33 by asuteau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------------- VARIABLES --------------------------------- #

SRCS = 	src/ft_printf.c \
		src/ft_printf_utils_nbr.c \
		src/ft_printf_utils_str.c \
		src/ft_printf_utils_addr.c \

OS = $(SRCS:.c=.o)

HD = inc

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

# ---------------------------------- RULES ----------------------------------- #

.c.o:
	$(CC) $(CFLAGS) -I $(HD) -c $< -o $(<:.c=.o)

$(NAME) : $(OS)
	ar rcs $(NAME) $(OS)

all: $(NAME)

clean:
	rm -f $(OS)

fclean: clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re
