/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:58:30 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/19 22:17:02 by amenses-         ###   ########.fr       */
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
# define NLEFT 3

typedef struct s_data
{
	int	val;
	int	s;
	int	r;
	int	rr;
	int	dist;
	int	i;
	int	target;
	int	fi;
	// int	dir;
	int	decision;
	// int	up[2];
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
	int	decision;
	int	size;
	int	direction;
	// int	max;
	// int min;
	// int	med;
	int	m[3];
	// int	range_a[2];
	// int	range_b[2];
	int	ra;
	int rra;
	int	r[3];
	int	rr[3];
	int	combo;
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
t_stack		*ft_stklast(t_stack *stk);
int			ft_abs(int n);
void	ft_arrcpy(int *dst, int *src, int nelem);

// ps_main
long long	ft_long_atoi(const char *nptr);
void	ft_error(char *msg);
void	ft_term_pushswap(char *msg, t_stack **stk);

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
void	ft_employop(t_stack **stk_a, t_stack **stk_b, char *op, int print);

// ps_algo
int			*ft_stktoarr(t_stack *stk, int size);
int			*ft_arrsort(int *arr, int size);
t_stack		*ft_stksort(t_stack *stk);
int			ft_stkindex(int index, int size);
int			ft_idist(int ci, int ti, int size);
// void		ft_set_scores(t_stack **s);
void		ft_set_scores(t_stack **s, t_utils *u);
int			ft_stkmax(t_stack *stk);
int			ft_stkmin(t_stack *stk);
void	ft_direction(t_stack *s, t_utils *u);
// void	ft_upscore(t_stack **s);
void	ft_move(t_stack **s, t_utils *u);
// void		ft_move(t_stack **s);
int			ft_minabs(int a, int b);
void	ft_moveup(t_stack **s);

// int			*ft_sortstk_arr(t_stack *stk);
void		ft_index(t_stack **stk);
int			ft_stkfind(t_stack *stk, int value);
int			ft_arrfind(int *arr, int value, int size);
void		ft_finalindex(t_stack **s, t_utils u);
void		ft_set_indexes(t_stack **stk);
int			ft_entropy(t_stack *stk);

// tmp
void		printstk(t_stack *stk);
void	printboth(t_stack *a, t_stack *b);
int			ft_indexdist(int i, int target, int nelem);
void	rev_printstk(t_stack *stk);
void	ft_sortstack(t_stack **s);
int		ft_stkmed(t_stack *stk);
void	ft_halfstk(t_stack **stk_a, t_stack **stk_b);
int		ft_mfind(int value, t_utils u);
void	ft_pa_ra(t_stack *a, t_stack **stk_b, t_utils u);
void	ft_pa_costs(t_stack **stk_a, t_stack **stk_b, t_utils u);
void	ft_setops(int *r_ops, int *rr_ops, int combo);
int	ft_findmin(int *arr, int nelem);
void	ft_pa_decision(t_stack *b, t_utils *u);
// void	ft_n3sort(t_stack **a, t_stack **b);
void	ft_n3sort(t_stack **stk_a);

#endif