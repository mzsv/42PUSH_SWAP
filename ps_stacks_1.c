/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stacks_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:39:32 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/20 01:26:34 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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

int	*ft_stktoarr(t_stack *stk, int size)
{
	int		*r;
	int		i;

	if (!stk || !size)
		return (NULL);
	r = malloc(sizeof(int) * size);
	if (!r)
		return (NULL);
	i = 0;
	while (stk)
	{
		r[i] = stk->data->val;
		stk = stk->next;
		i++;
	}
	return (r);
}

int	ft_stkmin(t_stack *stk)
{
	t_stack	*t;
	int		min;

	t = stk;
	min = INTMAX;
	while (stk)
	{
		if (stk->data->val < min)
			min = stk->data->val;
		stk = stk->next;
	}
	stk = t;
	return (min);
}

int	ft_stkmax(t_stack *stk)
{
	t_stack	*t;
	int		max;

	t = stk;
	max = INTMIN;
	while (stk)
	{
		if (stk->data->val > max)
			max = stk->data->val;
		stk = stk->next;
	}
	stk = t;
	return (max);
}

int	ft_stkmed(t_stack *stk)
{
	int	*sor;
	int	med;

	sor = ft_stktoarr(stk, ft_stksize(stk));
	sor = ft_arrsort(sor, ft_stksize(stk));
	med = sor[ft_stksize(stk) / 2];
	free(sor);
	return (med);
}
