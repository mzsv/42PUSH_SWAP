/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:33:54 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/15 03:52:15 by amenses-         ###   ########.fr       */
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

void	ft_sortstack(t_stack **s)
{
	t_stack	*stk;
	t_utils	u;

	stk = *s;
	ft_bzero(&u, sizeof(t_utils));
	u.size = ft_stksize(stk);
	u.max = ft_stkmax(stk);
	u.min = ft_stkmin(stk);
	ft_set_indexes(&stk);
	printstk(stk);
	int m=0;
	while (ft_entropy(stk))
	{
		// sleep(3);
		// ft_printf("\nMOVE(%d)\n", m);
		ft_direction(stk, &u);
		ft_set_indexes(&stk);
		ft_move(&stk, &u);
		// ft_printf("\n");
		// printstk(stk);
		// ft_printf("entropy=%d\n", ft_entropy(a));
		// ft_printf("decision=%d\n", u.decision);
		// ft_direction(a, &u);
		// ft_printf("\n");
		m++;
	}
	ft_printf("RESULT=%d\n", m);
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

void	ft_halfstk(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*ta;
	t_stack	*tb;
	int		med;
	int		i;
	int		size;

	a = *stk_a;
	b = *stk_b;
	ta = a;
	tb = b;
	med = ft_stkmed(*stk_a);
	ft_printf("MED=%d\n", med);
	size = ft_stksize(*stk_a);
	i = 0;
	while (i < size)
	{
		if ((*stk_a)->data->val >= med)
		{
			// ft_printf("(%d>%d)", (*stk_a)->data->val, med);
			pb(stk_a, stk_b);
		}
		else
			ra(stk_a, stk_b);
		// break ;
		i++;
	}
	// a = ta;
	/* ft_printf("_a_\n");
	printstk(*stk_a);
	ft_printf("_b_\n");
	printstk(*stk_b); */
}

void	ft_set_limits(t_stack *stk, t_utils *u)
{
	u->max = ft_stkmax(stk);
	u->min = ft_stkmin(stk);
	u->med = ft_stkmed(stk);
	u->size = ft_stksize(stk);
	u->m[0] = ft_stkmin(stk);
	u->m[1] = ft_stkmed(stk);
	u->m[2] = ft_stkmax(stk);
}

int	ft_mfind(int value, t_utils u)
{
	int	i;

	i = 0;
	while (i < u.size)
	{
		if (value == u.m[i])
			return (1);
		i++;
	}
	return (0);
}

/* void	ft_stkrescale(t_stack **stk)
{
	t_stack	*t;

	if (!*stk)
		return ;
	ft_set_indexes(stk);
	t = *stk;
	while (*stk)
	{
		
		(*stk) = (*stk)->next;
	}
} */

void	ft_n3sort(t_stack **stk_a, t_stack **stk_b)
{
	t_utils	u;
	int		i;
	t_stack	*a;
	t_stack	*b;

	ft_set_limits(*stk_a, &u);
	ft_set_indexes(stk_a);
	i = 0;
	while (i < u.size)
	{
		if (!ft_mfind((*stk_a)->data->val, u))
			pb(stk_a, stk_b);
		else
			ra(stk_a, stk_b);
		i++;
	}
	ft_printf("_a_\n");
	printstk(*stk_a);
	ft_printf("_b_\n");
	printstk(*stk_b);
	ft_printf("\n");
	a = *stk_a;
	b = *stk_b;
	int count=0;
	while (ft_stksize(a) < u.size && count < 500000)
	{
		ft_printf("(%d==%d)", a->data->target_index, b->data->target_index + 1);
		if (a->data->target_index == b->data->target_index + 1)
			pa(&a, &b);
		else
			ra(&a, &b);
		count++;
	}
	ft_sortstack(&a);
	ft_printf("_a_\n");
	printstk(a);
	ft_printf("_b_\n");
	printstk(b);
	ft_printf("\n");
}
