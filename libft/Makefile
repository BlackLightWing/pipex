# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msorbell <msorbell@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 11:21:00 by msorbell          #+#    #+#              #
#    Updated: 2023/04/18 14:20:44 by msorbell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG = libft.a

FLAGS = -Wall -Werror -Wextra

SRC =	ft_bzero.c \
		ft_calloc.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_split.c \
		ft_strcpy.c \
		ft_putstr_fd.c \

OBJ = $(SRC:.c=.o)

all: $(PROG)

$(OBJ):
	@gcc -c $(FLAGS) $(SRC)

$(PROG): $(OBJ)
	@ar rc $(PROG) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(PROG)

re : fclean all

