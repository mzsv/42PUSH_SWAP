/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:56:39 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/09 01:50:20 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	*ft_stktoarr(t_stack *stk, int size)
{
	int		*r;
	int		i;

	r = malloc(sizeof(int) * size);
	if (!r)
		return (NULL);
	i = 0;
	while (stk)
	{
		r[i] = stk->val;
		stk = stk->next;
		i++;
	}
	return (r);
}

int	*ft_sortstk_arr(t_stack *stk)
{
	t_stack	*t;
	int		tmp;

	t = stk;
	tmp = 0;
	while (stk->next)
	{
		if (stk->val > stk->next->val)
		{
			tmp = stk->val;
			stk->val = stk->next->val;
			stk->next->val = tmp;
			stk = t;
		}
		else
			stk = stk->next;
	}
	stk = t;
	return (ft_stktoarr(stk, ft_stksize(stk)));
}

/* t_stack	*ft_sortstk(t_stack *stk)
{
	t_stack	*t;
	int		tmp;

	if (!stk)
		return (NULL);
	t = stk;
	tmp = 0;
	while (stk->next)
	{
		if (stk->val > stk->next->val)
		{
			tmp = stk->val;
			stk->val = stk->next->val;
			stk->next->val = tmp;
			stk = t;
		}
		else
			stk = stk->next;
	}
	return (t);
} */

/* int		ft_findinstk(t_stack *stk, int value)
{
	int	i;

	if (!stk)
		return (-1);
	i = 0;
	while (stk)
	{
		if (stk->val == value)
			return (i);
		stk = stk->next;
		i++;
	}
	return (-1);
} */

/* void	ft_set_indexes(t_stack **stk)
{
	t_stack	*t;
	int		i;
	int		j;
	int		*sorted;

	if (!stk)
		return ;
	sorted = ft_sortstk_arr(*stk);
	t = *stk;
	i = 0;
	while (t)
	{
		if (t->val == sorted[i])
			
		t = t->next;
		i++;
	}
	free(sorted);
} */
