/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:58:14 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/18 04:11:20 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	sa(t_stack **a, t_stack **b)
{
	t_data	*t;

	(void)b;
	if (ft_stksize(*a) < 2)
		return ;
	t = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = t;
	// ft_printf("|sa|\n");
}

/* void	sa(t_stack *a, t_stack *b)
{
	int t;

	(void)b;
	if (ft_stksize(a) < 2)
		return ;
	t = a->val;
	a->val = a->next->val;
	a->next->val = t;
} */

void	sb(t_stack **a, t_stack **b)
{
	t_data	*t;

	(void)a;
	if (ft_stksize(*b) < 2)
		return ;
	t = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = t;
	// ft_printf("|sb|\n");
}

/* void	sb(t_stack *a, t_stack *b)
{
	int t;

	(void)a;
	if (ft_stksize(b) < 2)
		return ;
	t = b->val;
	b->val = b->next->val;
	b->next->val = t;
} */

void	ss(t_stack **a, t_stack **b)
{
	sa(a, b);
	sb(a, b);
	// ft_printf("|ss|\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*t;

	if (!*b)
		return ;
	t = *b;
	*b = t->next;
	t->next = NULL;
	if (!*a)
		*a = t;
	else
		ft_stkadd_first(a, t);
	// ft_printf("|pa|\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*t;

	if (!*a)
		return ;
	t = *a;
	*a = t->next;
	t->next = NULL;
	if (!*b)
		*b = t;
	else
		ft_stkadd_first(b, t);
	// ft_printf("|pb|\n");
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
	// ft_printf("|ra|\n");
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
	// ft_printf("|rb|\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, b);
	rb(a, b);
	// ft_printf("|rr|\n");
}

void	rra(t_stack **a, t_stack **b)
{
	t_stack	*t;

	// ft_printf("(test)");
	(void)b;
	if (!*a || (ft_stksize(*a) < 2))
		return ;
	t = *a;
	while (t->next->next)
		t = t->next;
	ft_stkadd_first(a, t->next);
	t->next = NULL;
	// ft_printf("|rra|\n");
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
	// ft_printf("|rrb|\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, b);
	rrb(a, b);
	// ft_printf("|rrr|\n");
}
