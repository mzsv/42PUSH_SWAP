/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_two_stacks_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:13:46 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/20 01:07:22 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_zeroexcept(int *r_ops, int pos1, int *rr_ops, int pos2)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (i != pos1)
			r_ops[i] = 0;
		if (i != pos2)
			rr_ops[i] = 0;
		i++;
	}
}

void	ft_setops(int *r_ops, int *rr_ops, int combo)
{
	if (combo == 0)
	{
		r_ops[0] -= r_ops[2];
		r_ops[1] -= r_ops[2];
		ft_bzero(rr_ops, sizeof(int) * 3);
	}
	if (combo == 1)
		ft_zeroexcept(r_ops, 0, rr_ops, 1);
	if (combo == 2)
		ft_zeroexcept(r_ops, 1, rr_ops, 0);
	if (combo == 3)
	{
		rr_ops[0] -= rr_ops[2];
		rr_ops[1] -= rr_ops[2];
		ft_bzero(r_ops, sizeof(int) * 3);
	}
}

void	ft_pa_decision(t_stack *b, t_utils *u)
{
	t_stack	*t;
	int		tmp;
	int		i;

	t = b;
	u->combo = ft_findmin(b->data->pa, 4);
	tmp = b->data->pa[u->combo];
	ft_arrcpy(u->r, b->data->pa_r, 3);
	ft_arrcpy(u->rr, b->data->pa_rr, 3);
	while (b->next && tmp > 1)
	{
		b = b->next;
		i = ft_findmin(b->data->pa, 4);
		if (b->data->pa[i] < tmp)
		{
			u->combo = i;
			tmp = b->data->pa[u->combo];
			ft_arrcpy(u->r, b->data->pa_r, 3);
			ft_arrcpy(u->rr, b->data->pa_rr, 3);
		}
	}
	ft_setops(u->r, u->rr, u->combo);
	b = t;
}

void	ft_r_employops(t_stack **stk_a, t_stack **stk_b, int *r_ops)
{
	int	i;

	i = 0;
	while (i < r_ops[0])
	{
		ft_employop(stk_a, stk_b, "ra\n", 1);
		i++;
	}
	i = 0;
	while (i < r_ops[1])
	{
		ft_employop(stk_a, stk_b, "rb\n", 1);
		i++;
	}
	i = 0;
	while (i < r_ops[2])
	{
		ft_employop(stk_a, stk_b, "rr\n", 1);
		i++;
	}
}

void	ft_rr_employops(t_stack **stk_a, t_stack **stk_b, int *rr_ops)
{
	int	i;

	i = 0;
	while (i < rr_ops[0])
	{
		ft_employop(stk_a, stk_b, "rra\n", 1);
		i++;
	}
	i = 0;
	while (i < rr_ops[1])
	{
		ft_employop(stk_a, stk_b, "rrb\n", 1);
		i++;
	}
	i = 0;
	while (i < rr_ops[2])
	{
		ft_employop(stk_a, stk_b, "rrr\n", 1);
		i++;
	}
}
