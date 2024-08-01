/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:12:47 by amenses-          #+#    #+#             */
/*   Updated: 2024/08/01 23:03:16 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps.h"

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

void	ft_employop(t_stack **stk_a, t_stack **stk_b, char *op, int print)
{
	if (!ft_strncmp(op, "ra\n", ft_strlen(op) + 1))
		ra(stk_a, stk_b);
	else if (!ft_strncmp(op, "rb\n", ft_strlen(op) + 1))
		rb(stk_a, stk_b);
	else if (!ft_strncmp(op, "rr\n", ft_strlen(op) + 1))
		rr(stk_a, stk_b);
	else if (!ft_strncmp(op, "rra\n", ft_strlen(op) + 1))
		rra(stk_a, stk_b);
	else if (!ft_strncmp(op, "rrb\n", ft_strlen(op) + 1))
		rrb(stk_a, stk_b);
	else if (!ft_strncmp(op, "rrr\n", ft_strlen(op) + 1))
		rrr(stk_a, stk_b);
	else if (!ft_strncmp(op, "pa\n", ft_strlen(op) + 1))
		pa(stk_a, stk_b);
	else if (!ft_strncmp(op, "pb\n", ft_strlen(op) + 1))
		pb(stk_a, stk_b);
	else if (!ft_strncmp(op, "sa\n", ft_strlen(op) + 1))
		sa(stk_a, stk_b);
	else if (!ft_strncmp(op, "sb\n", ft_strlen(op) + 1))
		sb(stk_a, stk_b);
	else if (!ft_strncmp(op, "ss\n", ft_strlen(op) + 1))
		ss(stk_a, stk_b);
	if (print)
		ft_printf("%s", op);
}
