/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stacks_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:33:13 by amenses-          #+#    #+#             */
/*   Updated: 2024/08/01 23:03:10 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps.h"

t_stack	*ft_stknew(int value)
{
	t_stack		*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = malloc(sizeof(t_data));
	if (!node->data)
		return (NULL);
	ft_bzero(node->data, sizeof(t_data));
	node->data->val = value;
	node->data->decision = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_stkadd_last(t_stack **stk, t_stack *new)
{
	t_stack	*t;

	if (!*stk)
	{
		*stk = new;
		new->next = NULL;
		new->prev = NULL;
		return ;
	}
	t = *stk;
	t->prev = NULL;
	while (t->next)
	{
		t = t->next;
	}
	new->prev = t;
	t->next = new;
}

void	ft_stkadd_first(t_stack **stk, t_stack *new)
{
	if (!stk || !new)
		return ;
	(*stk)->prev = new;
	new->next = *stk;
	new->prev = NULL;
	*stk = new;
}

t_stack	*ft_stklast(t_stack *stk)
{
	if (!stk || !stk->next)
		return (stk);
	while (stk->next)
		stk = stk->next;
	return (stk);
}

void	ft_stkclear(t_stack **stk)
{
	t_stack	*t;
	t_stack	*u;

	if (!*stk)
		return ;
	t = *stk;
	while (t)
	{
		u = t->next;
		free(t->data);
		free(t);
		t = u;
	}
	*stk = NULL;
}
