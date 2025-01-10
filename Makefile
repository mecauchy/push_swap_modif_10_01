# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 20:45:33 by mcauchy-          #+#    #+#              #
#    Updated: 2025/01/04 17:54:31 by mcauchy-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

SRCS_FILES	=	push_swap.c utils.c move.c singleton.c parsing.c simple_sort.c 

SRC_DIR		=	srcs

SRCS		=	$(addprefix $(SRC_DIR)/, $(SRCS_FILES))

OBJS		=	$(addprefix $(SRC_DIR)/, $(SRCS_FILES:.c=.o))

HEADER		=	-I includes/push_swap.h

CC			=	cc 

RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
			@echo "Compilation done !"

%.o:		%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compilation of $< done !"

clean:
			/bin/rm -rf $(OBJS)
			@echo "Objects deleted !"

fclean:		clean
			/bin/rm -rf $(NAME)
			@echo "Executable deleted !"

re:			fclean all

.PHONY:		all clean fclean re%
