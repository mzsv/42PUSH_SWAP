/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops_pushswap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:14:55 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/19 22:15:38 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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
}

void	sa(t_stack **a, t_stack **b)
{
	t_data	*t;

	(void)b;
	if (ft_stksize(*a) < 2)
		return ;
	t = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = t;
}

void	sb(t_stack **a, t_stack **b)
{
	t_data	*t;

	(void)a;
	if (ft_stksize(*b) < 2)
		return ;
	t = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = t;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, b);
	sb(a, b);
}
