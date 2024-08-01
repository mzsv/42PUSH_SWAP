/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:08:18 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/20 01:15:02 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_set_limits(t_stack *stk, t_utils *u)
{
	u->size = ft_stksize(stk);
	u->m[0] = ft_stkmin(stk);
	u->m[1] = ft_stkmed(stk);
	u->m[2] = ft_stkmax(stk);
}

int	ft_mfind(int value, t_utils u)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (value == u.m[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_findmin(int *arr, int nelem)
{
	int	i;
	int	r;

	i = 1;
	r = 0;
	while (i < nelem)
	{
		if (arr[i] < arr[r])
			r = i;
		i++;
	}
	return (r);
}

int	ft_stkindex(int index, int size)
{
	if (index < 0)
		return (size - (ft_abs(index) % size));
	if (index > size - 1)
		return (index % size);
	return (index);
}

int	ft_indexdist(int i, int target, int nelem)
{
	int	d1;
	int	d2;

	if (target > i)
	{
		d1 = target - i;
		d2 = nelem - d1;
		if (d1 <= d2)
			return (d1);
		return (-d2);
	}
	if (target < i)
	{
		d1 = i - target;
		d2 = nelem - d1;
		if (d1 <= d2)
			return (-d1);
		return (d2);
	}
	return (0);
}
