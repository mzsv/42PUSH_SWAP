# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 23:31:48 by amenses-          #+#    #+#              #
#    Updated: 2023/02/20 01:31:20 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror

LIBFT			=	libft/libft.a

SRCS			=	ps_main.c ps_ops_pushswap.c ps_ops_revrotation.c \
					ps_ops_rotation.c ps_sort_one_stack_0.c ps_sort_one_stack_1.c \
					ps_sort_two_stacks_0.c ps_sort_two_stacks_1.c \
					ps_sort_two_stacks_2.c ps_sort_utils.c ps_stacks_0.c \
					ps_stacks_1.c ps_utils.c ps_validations.c \
					
SRCS_BONUS		=	ps_checker_main_bonus.c ps_checker_ops_bonus.c \
					ps_checker_utils_bonus.c ps_ops_pushswap.c \
					ps_ops_revrotation.c ps_stacks_0.c ps_stacks_1.c \
					ps_ops_rotation.c ps_utils.c ps_validations.c \

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
