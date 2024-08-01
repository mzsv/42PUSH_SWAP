/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:16:20 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/20 21:55:11 by amenses-         ###   ########.fr       */
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
	int	i;
	int	target;
	int	fi;
	int	dist;
	int	s;
	int	r;
	int	rr;
	int	decision;
	int	pa_r[3];
	int	pa_rr[3];
	int	pa[4];
}	t_data;

typedef struct s_stack
{
	struct s_stack	*prev;
	t_data			*data;
	struct s_stack	*next;
}	t_stack;

typedef struct s_utils
{
	int	size;
	int	decision;
	int	direction;
	int	m[3];
	int	ra;
	int	rra;
	int	r[3];
	int	rr[3];
	int	combo;
}	t_utils;

void		ra(t_stack **a, t_stack **b);

void		rb(t_stack **a, t_stack **b);

void		rr(t_stack **a, t_stack **b);

void		ft_employop(t_stack **stk_a, t_stack **stk_b, char *op, int print);

void		rra(t_stack **a, t_stack **b);

void		rrb(t_stack **a, t_stack **b);

void		rrr(t_stack **a, t_stack **b);

void		pa(t_stack **a, t_stack **b);

void		pb(t_stack **a, t_stack **b);

void		sa(t_stack **a, t_stack **b);

void		sb(t_stack **a, t_stack **b);

void		ss(t_stack **a, t_stack **b);

void		ft_error(char *msg);

int			ft_check_input(int n, char **argv);

int			ft_check_dups(t_stack *stk);

int			ft_check_order(t_stack *stk);

t_stack		*ft_get_stack(int n, char **argv);

t_stack		*ft_stknew(int value);

void		ft_stkadd_last(t_stack **stk, t_stack *new);

void		ft_stkadd_first(t_stack **stk, t_stack *new);

t_stack		*ft_stklast(t_stack *stk);

void		ft_stkclear(t_stack **stk);

int			ft_stksize(t_stack *stk);

int			*ft_stktoarr(t_stack *stk, int size);

int			ft_stkmin(t_stack *stk);

int			ft_stkmax(t_stack *stk);

int			ft_stkmed(t_stack *stk);

long long	ft_long_atoi(const char *nptr);

int			ft_abs(int n);

void		ft_arrcpy(int *dst, int *src, int nelem);

int			*ft_arrsort(int *arr, int size);

int			ft_arrfind(int *arr, int value, int size);

void		ft_set_limits(t_stack *stk, t_utils *u);

int			ft_mfind(int value, t_utils u);

int			ft_findmin(int *arr, int nelem);

int			ft_stkindex(int index, int size);

int			ft_indexdist(int i, int target, int nelem);

void		ft_set_indexes(t_stack **stk);

int			ft_entropy(t_stack *stk);

void		ft_set_scores(t_stack **s, t_utils *u);

int			ft_downcheck(t_stack *stk, int min, int max);

int			ft_upcheck(t_stack *stk, int min, int max);

void		ft_direction(t_stack *stk, t_utils *u);

void		ft_rotate(t_stack **stk, t_utils *u);

void		ft_move(t_stack **s, t_utils *u);

void		ft_sortstack(t_stack **s);

void		ft_finalindex(t_stack **s, t_utils u);

void		ft_ra_score(t_stack *stk_a, t_stack **stk_b);

void		ft_pa_ra(t_stack *a, t_stack **stk_b, t_utils u);

void		ft_rotationcost(t_stack **stk_b, int size_a, int size_b);

void		ft_pa_costs(t_stack **stk_a, t_stack **stk_b, t_utils u);

void		ft_zeroexcept(int *r_ops, int pos1, int *rr_ops, int pos2);

void		ft_setops(int *r_ops, int *rr_ops, int combo);

void		ft_pa_decision(t_stack *b, t_utils *u);

void		ft_r_employops(t_stack **stk_a, t_stack **stk_b, int *r_ops);

void		ft_rr_employops(t_stack **stk_a, t_stack **stk_b, int *rr_ops);

void		ft_pb_move(t_stack **stk_a, t_stack **stk_b, t_utils u);

void		ft_movetoa(t_stack **stk_a, t_stack **stk_b, t_utils *u);

void		ft_n3sort(t_stack **stk_a);

void		ft_term_pushswap(char *msg, t_stack **stk);

#endif