# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 00:54:41 by amenses-          #+#    #+#              #
#    Updated: 2023/02/07 23:43:10 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror

LIBFT			=	libft/libft.a

SRCS			=	ps_init.c ps_main.c ps_ops_0.c ps_utils_0.c tmp.c \

OBJS			=	$(SRCS:.c=.o)

NAME			=	push_swap

all:				$(NAME)

$(NAME):			$(OBJS)
					$(MAKE) -C libft
					$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
					$(MAKE) clean -C libft
					$(RM) $(OBJS)

fclean:				clean
					$(MAKE) fclean -C libft
					$(RM) $(NAME)

re:					fclean all

.SILENT:
