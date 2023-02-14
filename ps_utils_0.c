/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:19:08 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/14 03:46:12 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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
	node->previous = NULL;
	return (node);
}

/* t_stack	*ft_stknew(int value)
{
	t_stack		*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->val = value;
	node->next = NULL;
	return (node);
} */

void	ft_stkadd_last(t_stack **stk, t_stack *new)
{
	t_stack	*t;

	if (!*stk)
	{
		*stk = new;
		new->next = NULL;
		new->previous = NULL;
		return ;
	}
	t = *stk;
	t->previous = NULL;
	while (t->next)
	{
		t = t->next;
	}
	new->previous = t;
	t->next = new;
}

void	ft_stkadd_first(t_stack **stk, t_stack *new)
{
	if (!stk || !new)
		return ;
	new->next = *stk;
	new->previous = NULL;
	*stk = new;
}

int	ft_stksize(t_stack *stk)
{
	int	i;

	i = 0;
	while (stk)
	{
		stk = stk->next;
		i++;
	}
	return (i);
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

long long	ft_long_atoi(const char *nptr)
{
	long long	res;
	int			sign;

	sign = 1;
	res = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while ((*nptr >= 48 && *nptr <= 57) && *nptr)
	{
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	return (res * sign);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}