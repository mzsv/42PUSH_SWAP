/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:58:14 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/09 00:21:35 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	sa(t_stack *a, t_stack *b)
{
	int t;

	(void)b;
	if (ft_stksize(a) < 2)
		return ;
	t = a->val;
	a->val = a->next->val;
	a->next->val = t;
}

void	sb(t_stack *a, t_stack *b)
{
	int t;

	(void)a;
	if (ft_stksize(b) < 2)
		return ;
	t = b->val;
	b->val = b->next->val;
	b->next->val = t;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, b);
	sb(a, b);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*t;

	if (!*b)
		return ;
	t = *b;
	*b = t->next;
	t->next = NULL;
	ft_stkadd_first(a, t);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*t;

	if (!*a)
		return ;
	t = *a;
	*a = t->next;
	t->next = NULL;
	ft_stkadd_first(b, t);
}

void	ra(t_stack **a, t_stack **b)
{
	t_stack	*t;

	if (!*a)
		return ;
	(void)b;
	t = *a;
	*a = t->next;
	t->next = NULL;
	ft_stkadd_last(a, t);
}

void	rb(t_stack **a, t_stack **b)
{
	t_stack	*t;

	if (!*b)
		return ;
	(void)a;
	t = *b;
	*b = t->next;
	t->next = NULL;
	ft_stkadd_last(b, t);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, b);
	rb(a, b);
}

void	rra(t_stack **a, t_stack **b)
{
	t_stack	*t;

	(void)b;
	if (!*a || (ft_stksize(*a) < 2))
		return ;
	t = *a;
	while (t->next->next)
		t = t->next;
	ft_stkadd_first(a, t->next);
	t->next = NULL;
}

void	rrb(t_stack **a, t_stack **b)
{
	t_stack	*t;

	(void)a;
	if (!*b || (ft_stksize(*b) < 2))
		return ;
	t = *b;
	while (t->next->next)
		t = t->next;
	ft_stkadd_first(b, t->next);
	t->next = NULL;
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, b);
	rrb(a, b);
}
