/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:56:39 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/10 01:46:30 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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

int	*ft_arrsort(int *arr, int size)
{
	int	i;
	int	tmp;

	if (!arr || !size)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			// ft_printf("(test=%d", arr[i]);
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			// ft_printf("->%d)", arr[i]);
			i = 0;
		}
		else
			i++;
	}
	return (arr);
}

/* int	*ft_stktoarr(t_stack *stk, int size)
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
} */

t_stack	*ft_stksort(t_stack *stk)
{
	t_stack	*t;
	int		tmp;

	t = stk;
	tmp = 0;
	while (stk->next)
	{
		if (stk->data->val > stk->next->data->val)
		{
			tmp = stk->data->val;
			stk->data->val = stk->next->data->val;
			stk->next->data->val = tmp;
			stk = t;
		}
		else
			stk = stk->next;
	}
	stk = t;
	return (stk);
}

/* int	*ft_sortstk_arr(t_stack *stk)
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
} */

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

int		ft_stkfind(t_stack *stk, int value)
{
	int	i;

	if (!stk)
		return (-1);
	i = 0;
	while (stk)
	{
		if (stk->data->val == value)
			return (i);
		stk = stk->next;
		i++;
	}
	return (-1);
}

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

int	ft_arrfind(int *arr, int value, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_set_indexes(t_stack **stk)
{
	t_stack	*t;
	int		i;
	int		*sorted;
	int		size;

	if (!stk)
		return ;
	t = *stk;
	size = ft_stksize(t);
	sorted = ft_stktoarr(t, size);
	sorted = ft_arrsort(sorted, size);
	ft_printf("sorted: ");
	ft_printarr(sorted, size);
	i = 0;
	while (t)
	{
		t->data->target_index = ft_arrfind(sorted, t->data->val, size);
		// ft_printf("test=%d\n", t->data->target_index);
		// ft_printf("test=%d\n", t->data->val);
		// ft_printf("testindex=%d\n", t->data->target_index);
		t->data->tmp_index = i;
		t->data->dist = ft_abs(t->data->tmp_index - t->data->target_index) % (size / 2 + 1);
		ft_printf("test=%d\n", t->data->dist);
		t = t->next;
		i++;
	}
	free(sorted);
}

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

int	ft_entropy(t_stack *stk)
{
	int		e;
	t_stack	*t;

	if (!stk)
		return (-1);
	t = stk;
	e = 0;
	while (stk)
	{
		e += ft_abs(stk->data->dist);
		stk = stk->next;
	}
	stk = t;
	return (e);
}

