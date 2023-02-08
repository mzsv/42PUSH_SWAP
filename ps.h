/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:58:30 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/08 01:27:38 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define INTMAX	2147483647
# define INTMIN	-2147483648

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
} t_stack;

// ps_init
int			ft_check_input(int n, char **argv);
t_stack		*ft_get_stack(int n, char **argv);
int			ft_check_dups(t_stack *stk);

// ps_utils_0
t_stack		*ft_stknew(int value);
void		ft_stkadd(t_stack **stk, t_stack *new);
int			ft_stksize(t_stack *stk);

// ps_main
void		ft_error(char *msg);
long long	ft_long_atoi(const char *nptr);

// ps_ops
void		sa(t_stack *a, t_stack *b);
void		sb(t_stack *a, t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);

// tmp
void		printstk(t_stack *stk);

#endif