/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:58:14 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/08 01:49:49 by amenses-         ###   ########.fr       */
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

void	pa(t_stack *a, t_stack *b)
{
	t_stack	*t;

	if (!b)
		return ;
	t = b;
	b->next = a;
	b = t->next;
	a = t;
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*t;

	if (!a)
		return ;
	t = b;
	b = a;
	b->next = NULL;
	a = a->next;
	printf("test");
}
