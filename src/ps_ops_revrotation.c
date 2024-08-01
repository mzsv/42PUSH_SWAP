/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops_revrotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:13:48 by amenses-          #+#    #+#             */
/*   Updated: 2024/08/01 23:02:58 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps.h"

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
