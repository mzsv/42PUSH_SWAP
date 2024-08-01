/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_one_stack_0.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:54:44 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/20 01:15:44 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_set_indexes(t_stack **stk)
{
	t_stack	*t;
	int		i;
	int		*sorted;
	int		size;

	if (!*stk)
		return ;
	t = *stk;
	size = ft_stksize(t);
	sorted = ft_stktoarr(t, size);
	sorted = ft_arrsort(sorted, size);
	i = 0;
	while (t)
	{
		t->data->target = ft_arrfind(sorted, t->data->val, size);
		t->data->i = i;
		t->data->dist = ft_indexdist(t->data->i, t->data->target, size);
		t = t->next;
		i++;
	}
	free(sorted);
}

int	ft_entropy(t_stack *stk)
{
	int		e;
	t_stack	*t;

	if (!stk)
		return (-1);
	t = stk;
	e = 0;
	while (stk)
	{
		e += ft_abs(stk->data->dist);
		stk = stk->next;
	}
	stk = t;
	return (e);
}

void	ft_set_scores(t_stack **s, t_utils *u)
{
	t_stack	*t;
	t_stack	*stk;

	stk = *s;
	t = stk;
	u->ra = 0;
	u->rra = 0;
	while (stk)
	{
		stk->data->r = ft_indexdist(ft_stkindex(stk->data->i - 1, u->size), \
			stk->data->target, u->size);
		u->ra += ft_abs(stk->data->r);
		stk->data->rr = ft_indexdist(ft_stkindex(stk->data->i + 1, u->size), \
			stk->data->target, u->size);
		u->rra += ft_abs(stk->data->rr);
		stk = stk->next;
	}
	stk = t;
}

int	ft_downcheck(t_stack *stk, int min, int max)
{
	int	i;
	int	stop;

	i = 0;
	stop = 0;
	while (stk->next)
	{
		if (!stop && !(stk->data->val > stk->next->data->val && \
			(stk->data->val != max || stk->next->data->val != min)))
			i++;
		else
			stop = 1;
		stk = stk->next;
	}
	return (i);
}

int	ft_upcheck(t_stack *stk, int min, int max)
{
	int	i;
	int	stop;

	i = 0;
	stop = 0;
	while (stk->prev)
	{
		if (!stop && !(stk->data->val < stk->prev->data->val && \
			(stk->data->val != min || stk->prev->data->val != max)))
			i++;
		else
			stop = 1;
		stk = stk->prev;
	}
	return (i);
}
