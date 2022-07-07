# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 12:17:38 by dfarhi            #+#    #+#              #
#    Updated: 2022/06/27 18:14:43 by ybentaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES		= minishell env_lst env_export env_update envlst_to_envp \
			  signals signals_utils

PARSING_FILES	= parsing utils_parsing nrml_args utils_linkedlist quote_parsing\
					check_error quote_error single_quote
PARSING_FILES	:= $(addprefix parsing/, ${PARSING_FILES})

EXECUTION_FILES	= exec pipe_info pipe_info_cmdargs pipe_info_redir_iofd heredoc \
				  pipe_info_pipes pathname_list exec_command builtin_exit \
				  builtin builtin_echo builtin_env builtin_export builtin_unset \
				  builtin_pwd builtin_cd
EXECUTION_FILES	:= $(addprefix execution/, ${EXECUTION_FILES})

FILES		:= $(FILES) $(PARSING_FILES) $(EXECUTION_FILES)
FILES		:= $(addprefix src/, ${FILES})
FILES		:= $(addsuffix .c, ${FILES})
OBJS		= ${FILES:.c=.o}

NAME		= minishell

CC			= gcc -Wall -Wextra -Werror

INCLUDES	= -I./includes -I./libft/includes

LIB			= -L./libft/ -lft -lreadline
LIBFT		= libft/libft.a
LIBFT_ARGS	=

SYSTEM		= $(shell uname -s)

${NAME}:	${LIBFT} ${OBJS}
			${CC} ${INCLUDES} -o ${NAME} ${OBJS} ${LIB}

.c.o:
			${CC} -c ${INCLUDES} $< -o ${<:.c=.o}

all:		${NAME}

ifeq ($(SYSTEM), Darwin)
LIB			:= $(LIB) -L $(HOME)/.brew/opt/readline/lib
INCLUDES	:= $(INCLUDES) -I$(HOME)/.brew/opt/readline/include
endif

AddressSanitizer:	CC := ${CC} -fsanitize=address -g
ifeq ($(SYSTEM), Linux)
AddressSanitizer:	CC := ${CC} -static-libasan
endif
AddressSanitizer:	LIBFT_ARGS := ${LIBFT_ARGS} ADDRESS_SANITIZER=1
AddressSanitizer:	${NAME}

# cmd to prof code:
# gprof ${NAME} gmon.out > analysis.txt
profile:	fclean
profile:	CC := ${CC} -pg
profile:	LIBFT_ARGS := ${LIBFT_ARGS} PROFILE=1
profile:	${NAME}

${LIBFT}:
			$(MAKE) -C ./libft expanded get-next-line ${LIBFT_ARGS}

git:
			git submodule update --init --recursive

clean:
			rm -f ${OBJS}
			make -C ./libft clean

fclean:		clean
			rm -f ${NAME} libft/libft.a

re:			fclean all

.PHONY:		all clean fclean re
