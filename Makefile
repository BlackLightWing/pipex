# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msorbell <msorbell@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 10:57:15 by msorbell          #+#    #+#              #
#    Updated: 2023/04/18 14:20:52 by msorbell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
NAME_B	= pipex

SRCS 	= basic_pipex/pipex.c basic_pipex/process.c basic_pipex/msg.c basic_pipex/path_finding.c
OBJS 	= ${SRCS:.c=.o}
MAIN	= basic_pipex/pipex.c

SRCS_B	= bonus_pipex/pipex_bonus.c bonus_pipex/process_bonus.c \
basic_pipex/msg.c basic_pipex/path_finding.c get_next_line/get_next_line.c \
get_next_line/get_next_line_utils.c
OBJS_B	= ${SRCS_B:.c=.o}
MAIN_B	= bonus_pipex/pipex_bonus.c

BAR	= includes/loading.sh

CFLAGS 	= -Wall -Wextra -Werror

.c.o:	%.o : %.c
	@gcc ${CFLAGS} -Iincludes -c $< -o $(<:.c=.o)

all:	${NAME}

${NAME}:	${OBJS}
	@touch outfile
	@echo "\033[33m		==========Compiling libft==========\x1b[0m\n"
	@bash ${BAR}
	@make re -C ./libft
	@echo "\033[32m		==========LIBFT Compiled=========\x1b[0m\n"
	@sleep 0.5
	@echo "\033[33m		==========Compiling Pipex==========\x1b[0m\n"
	@gcc ${OBJS} -Llibft -lft -o ${PROG}
	@bash ${BAR}
	@echo "\033[32m		==========Pipex Compiled==========\x1b[0m\n"


bonus:	${NAME_B}

${NAME_B}:	${OBJS_B}
	@touch outfile
	@echo "\033[33m		==========Compiling libft==========\x1b[0m\n"
	@make re -C ./libft
	@bash ${BAR}
	@echo "\033[32m		==========LIBFT Compiled=========\x1b[0m\n"
	@sleep 0.5
	@echo "\033[33m		==========Compiling Pipex==========\x1b[0m\n"
	@gcc ${OBJS_B} -Llibft -lft -o ${PROG_B}
	@bash ${BAR}
	@echo "\033[32m		==========Pipex Compiled==========\x1b[0m\n"

clean:
	@make clean -C ./libft
	@rm -f ${OBJS} ${OBJS_B}
	@rm -f outfile

fclean:	clean
	@make fclean -C ./libft
	@rm -f $(NAME)
	@rm -f ${NAME_B}
	@rm -f ${PROG}
	@echo "\n\033[31m		=========EVERYTHING DELETED=======\x1b[0m\n"

re:	fclean all

re_bonus:	fclean bonus
