# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 00:54:41 by amenses-          #+#    #+#              #
#    Updated: 2023/02/19 01:28:33 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror

LIBFT			=	libft/libft.a

SRCS			=	ps_init.c ps_main.c ps_ops_0.c ps_utils_0.c tmp.c ps_algo.c \

SRCS_BONUS		=	ps_checker_bonus.c ps_checker_utils_bonus.c tmp_checker.c \
					ps_utils_0.c ps_init.c ps_ops_0.c \

OBJS			=	$(SRCS:.c=.o)

OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)

NAME			=	push_swap

NAME_BONUS		=	checker

all:				$(NAME)

$(NAME):			$(OBJS)
					$(MAKE) -C libft
					$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus:				$(OBJS_BONUS)
					$(MAKE) -C libft
					$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

clean:
					$(MAKE) clean -C libft
					$(RM) $(OBJS) $(OBJS_BONUS)

fclean:				clean
					$(MAKE) fclean -C libft
					$(RM) $(NAME) $(NAME_BONUS)

re:					fclean all

.SILENT:
