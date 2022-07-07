# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 12:17:38 by dfarhi            #+#    #+#              #
#    Updated: 2022/05/27 14:43:52 by davifah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
	ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
SRCS	= $(addprefix mandatory/, ${SRC_FILES})
OBJS	= ${SRCS:.c=.o}

BONUS_FILES = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
	ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
	ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c \
	ft_lstsize_bonus.c
BONUSES	= $(addprefix bonus/, ${BONUS_FILES})
BON_OBJ	= ${BONUSES:.c=.o}

EXPANDED_FILES = ft_itoa_base.c ft_power.c ft_isspace.c ft_lstget_index.c \
				 ft_lstremove_index.c ft_strjoin3.c
EXPANDED = $(addprefix expanded/, ${EXPANDED_FILES})
EXP_OBJ	= ${EXPANDED:.c=.o}

GNL_FILES = get-next-line/get_next_line.c
GNL_OBJ	= ${GNL_FILES:.c=.o}

PRINTF_FILES = ft_printf.c manage_fi.c int_format.c uint_format.c ft_putlong_fd.c \
			char_format.c str_format.c hex_format.c ptr_format.c \
			ft_lluitoa_base.c
PRINTF	= $(addprefix ft_printf/src/, ${PRINTF_FILES})
PRINTF_OBJ = ${PRINTF:.c=.o}

INCLUDES = -I./includes

SYSTEM		= $(shell uname -s)

NAME	= libft.a

CC		= gcc -Wall -Wextra -Werror

AR		= ar rcs

ifdef ADDRESS_SANITIZER
CC		:= ${CC} -fsanitize=address -g
 ifeq ($(SYSTEM), Linux)
CC		:= ${CC} -static-libasan
 endif
endif

ifdef PROFILE
CC		:= ${CC} -pg
endif

.c.o:
			${CC} -c $< $(INCLUDES) -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

bonus:		${NAME} ${BON_OBJ}
			${AR} ${NAME} ${BON_OBJ}

expanded:	bonus ${EXP_OBJ}
			${AR} ${NAME} ${EXP_OBJ}

get-next-line: expanded ${GNL_OBJ}
			${AR} ${NAME} ${GNL_OBJ}

ft_printf:	expanded ${PRINTF_OBJ}
			${AR} ${NAME} ${PRINTF_OBJ}

clean:
			rm -f ${OBJS} ${BON_OBJ} ${GNL_OBJ} ${EXP_OBJ} ${PRINTF_OBJ}

# "Force clean" remove all compiled files
fclean:		clean
			rm -f ${NAME}

# Rule to recompile
re:			fclean all

# Rules that do not have files, if those files exist, they are ignored
.PHONY:		all clean fclean re bonus get-next-line ft_printf
