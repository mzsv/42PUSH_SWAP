/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:33:54 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/14 23:31:41 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	printstk(t_stack *stk)
{
	t_stack	*t;

	t = stk;
	while (stk)
	{
		// ft_printf("(test)");
		ft_printf("s%d(%d)\n", stk->data->val, stk->data->dist);
		// ft_printf("testprintstk=%d\n", stk->next == NULL);
		stk = stk->next;
	}
	stk = t;
}

void	rev_printstk(t_stack *stk)
{
	t_stack	*t;
	int	i;

	i = 0;
	t = stk;
	while (stk->next)
		stk = stk->next;
	while (stk)
	{
		// sleep(5);
		// ft_printf("(test)");
		ft_printf("%d_s%d(%d)\n", i, stk->data->val, stk->data->dist);
		// ft_printf("testprintstk=%d\n", stk->next == NULL);
		stk = stk->previous;
		if (!stk)
			ft_printf("(null)\n");
		i++;
	}
	stk = t;
}

/* void	printstk(t_stack *stk)
{
	while (stk)
	{
		ft_printf("s%d\n", stk->val);
		// ft_printf("testprintstk=%d\n", stk->next == NULL);
		stk = stk->next;
	}
} */

void	ft_printarr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d, ", arr[i]);
		i++;
	}
	ft_printf("\n");
}

/* int	ft_check_dups(t_stack *stk)
{
	t_stack	*t;

	t = stk;
	while (t->next)
	{
		while (stk->next)
		{
			// ft_printf("(value=%d, next=%d)", t->val, stk->next->val);
			if (t->val == stk->next->val)
				return (0);
			stk = stk->next;
		}
		t = t->next;
		stk = t;
	}
	return (1);
} */

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
