/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_two_stacks_0.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:01:57 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/20 00:26:05 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_finalindex(t_stack **s, t_utils u)
{
	int		*sorted;
	t_stack	*t;

	if (!*s)
		return ;
	t = *s;
	sorted = ft_stktoarr((*s), u.size);
	sorted = ft_arrsort(sorted, u.size);
	while ((*s))
	{
		(*s)->data->fi = ft_arrfind(sorted, (*s)->data->val, u.size);
		(*s) = (*s)->next;
	}
	*s = t;
	free(sorted);
}

void	ft_ra_score(t_stack *stk_a, t_stack **stk_b)
{
	t_stack	*ta;

	ta = stk_a;
	while (stk_a->next)
	{
		stk_a = stk_a->next;
		if ((*stk_b)->data->fi < stk_a->data->fi \
			&& (*stk_b)->data->fi > stk_a->prev->data->fi)
		{
			(*stk_b)->data->pa_r[0] = stk_a->data->i;
			break ;
		}
	}
	stk_a = ta;
}

void	ft_pa_ra(t_stack *a, t_stack **stk_b, t_utils u)
{
	t_stack	*tb;
	t_stack	*la;

	tb = *stk_b;
	la = ft_stklast(a);
	ft_set_indexes(&a);
	while ((*stk_b))
	{
		if ((*stk_b)->data->fi < a->data->fi && \
			((*stk_b)->data->fi > la->data->fi || la->data->fi == u.size - 1))
			(*stk_b)->data->pa_r[0] = 0;
		else
			ft_ra_score(a, stk_b);
		(*stk_b) = (*stk_b)->next;
	}
	*stk_b = tb;
}

void	ft_rotationcost(t_stack **stk_b, int size_a, int size_b)
{
	(*stk_b)->data->pa_r[1] = (*stk_b)->data->i;
	(*stk_b)->data->pa_r[2] = ft_min((*stk_b)->data->pa_r[0], \
		(*stk_b)->data->pa_r[1]);
	(*stk_b)->data->pa_rr[0] = size_a - (*stk_b)->data->pa_r[0];
	(*stk_b)->data->pa_rr[1] = size_b - (*stk_b)->data->pa_r[1];
	(*stk_b)->data->pa_rr[2] = ft_min((*stk_b)->data->pa_rr[0], \
		(*stk_b)->data->pa_rr[1]);
}

void	ft_pa_costs(t_stack **stk_a, t_stack **stk_b, t_utils u)
{
	t_stack	*t;
	int		size_a;
	int		size_b;

	if (!*stk_b)
		return ;
	t = *stk_b;
	size_a = ft_stksize(*stk_a);
	size_b = ft_stksize(*stk_b);
	ft_pa_ra(*stk_a, stk_b, u);
	ft_set_indexes(stk_b);
	while ((*stk_b))
	{
		ft_rotationcost(stk_b, size_a, size_b);
		(*stk_b)->data->pa[0] = ft_max((*stk_b)->data->pa_r[0], \
			(*stk_b)->data->pa_r[1]);
		(*stk_b)->data->pa[1] = (*stk_b)->data->pa_r[0] + \
			(*stk_b)->data->pa_rr[1];
		(*stk_b)->data->pa[2] = (*stk_b)->data->pa_rr[0] + \
			(*stk_b)->data->pa_r[1];
		(*stk_b)->data->pa[3] = ft_max((*stk_b)->data->pa_rr[0], \
			(*stk_b)->data->pa_rr[1]);
		(*stk_b) = (*stk_b)->next;
	}
	*stk_b = t;
}
