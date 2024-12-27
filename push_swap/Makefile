# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 13:10:49 by gcarrico          #+#    #+#              #
#    Updated: 2024/12/11 16:00:20 by gcarrico         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= push_swap

LIBFT				= ./libft/libft.a
INC					= inc/
SRC_DIR				= srcs/
OBJ_DIR				= obj/

CC					= gcc
CFLAGS				= -Wall -Wextra -Werror -I
RM					= rm -fr


PUSH_SWAP_DIR		= $(SRC_DIR)push_swap/error_handling.c \
						$(SRC_DIR)push_swap/push_swap.c	\
						$(SRC_DIR)push_swap/split_str.c \
						$(SRC_DIR)push_swap/stack_help.c \
						$(SRC_DIR)push_swap/stack_init.c

SRCS				= $(PUSH_SWAP_DIR)

OBJ			        = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:
					@make all

$(LIBFT):
					@make -C ./libft

all:				$(NAME)

$(NAME):			$(OBJ) $(LIBFT)
							@$(CC)	$(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:			$(SRC_DIR)%.c
							@mkdir -p $(@D)
							@$(CC) $(CFLAGS) $(INC) -C $< -o $@ 

clean:
							@$(RM) -r $(OBJ_DIR)
							@make clean -C ./libft

fclean:				clean
							@$(RM) $(NAME)
							@$(RM) $(LIBFT)

re:					fclean all

.PHONY:				start all clean fclean re