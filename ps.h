/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:58:30 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/14 03:35:53 by amenses-         ###   ########.fr       */
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

typedef struct s_data
{
	int	val;
	int	s;
	int	r;
	int	rr;
	int	dist;
	int	tmp_index;
	int	target_index;
	int	dir;
	int	decision;
	int	up[2];
}	t_data;

typedef struct s_stack
{
	struct s_stack	*previous;
	t_data			*data;
	struct s_stack	*next;
}	t_stack;

typedef struct s_utils
{
	int	decision;
	int	size;
	int	direction;
}	t_utils;

// ps_init
int			ft_check_input(int n, char **argv);
int			ft_check_order(t_stack *stk);
t_stack		*ft_get_stack(int n, char **argv);
void		ft_printarr(int *arr, int size);
int			ft_check_dups(t_stack *stk);

// ps_utils_0
t_stack		*ft_stknew(int value);
void		ft_stkadd_last(t_stack **stk, t_stack *new);
void		ft_stkadd_first(t_stack **stk, t_stack *new);
int			ft_stksize(t_stack *stk);
void		ft_stkclear(t_stack **stk);
int			ft_abs(int n);

// ps_main
void		ft_error(char *msg);
long long	ft_long_atoi(const char *nptr);

// ps_ops
void		sa(t_stack **a, t_stack **b);
void		sb(t_stack **a, t_stack **b);
void		ss(t_stack **a, t_stack **b);
// void		sa(t_stack *a, t_stack *b);
// void		sb(t_stack *a, t_stack *b);
// void		ss(t_stack *a, t_stack *b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		ra(t_stack **a, t_stack **b);
void		rb(t_stack **a, t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a, t_stack **b);
void		rrb(t_stack **a, t_stack **b);
void		rrr(t_stack **a, t_stack **b);

// ps_algo
int			*ft_stktoarr(t_stack *stk, int size);
int			*ft_arrsort(int *arr, int size);
t_stack		*ft_stksort(t_stack *stk);
int			ft_stkindex(int index, int size);
int			ft_idist(int ci, int ti, int size);
void		ft_set_scores(t_stack **s);
int			ft_stkmax(t_stack *stk);
int			ft_stkmin(t_stack *stk);
void	ft_direction(t_stack *s, t_utils *u);
// void	ft_upscore(t_stack **s);
void	ft_move(t_stack **s, t_utils u);
// void		ft_move(t_stack **s);
int			ft_minabs(int a, int b);
void	ft_moveup(t_stack **s);

// int			*ft_sortstk_arr(t_stack *stk);
void		ft_index(t_stack **stk);
int			ft_stkfind(t_stack *stk, int value);
int			ft_arrfind(int *arr, int value, int size);
void		ft_set_indexes(t_stack **stk);
int			ft_entropy(t_stack *stk);

// tmp
void		printstk(t_stack *stk);
int			ft_indexdist(int i, int target, int nelem);
void	rev_printstk(t_stack *stk);

#endif