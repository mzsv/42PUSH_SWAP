/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:19:08 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/09 01:52:36 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_stack	*ft_stknew(int value)
{
	t_stack		*node;
	// t_weight	w;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	// ft_bzero(&w, sizeof(t_weight));
	node->val = value;
	node->next = NULL;
	return (node);
}

void	ft_stkadd_last(t_stack **stk, t_stack *new)
{
	t_stack	*t;

	if (!*stk)
	{
		*stk = new;
		new->next = NULL;
		return ;
	}
	t = *stk;
	while (t->next)
	{
		t = t->next;
	}
	t->next = new;
}

void	ft_stkadd_first(t_stack **stk, t_stack *new)
{
	if (!stk || !new)
		return ;
	new->next = *stk;
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
