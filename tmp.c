/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:33:54 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/17 00:06:38 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	printstk(t_stack *stk)
{
	t_stack	*t;

	if (!stk)
	{
		ft_printf("(empty)\n");
		return ;
	}
	t = stk;
	while (stk)
	{
		// ft_printf("(test)");
		ft_printf("s%d(%d)(t%d)(f%d)\n", stk->data->val, stk->data->dist, stk->data->target_index, stk->data->final);
		// ft_printf("testprintstk=%d\n", stk->next == NULL);
		stk = stk->next;
	}
	stk = t;
}

void	rev_printstk(t_stack *stk)
{
	t_stack	*t;
	int	i;

	if (!stk)
	{
		ft_printf("(empty)\n");
		return ;
	}
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
	ft_set_indexes(s);
	printstk(*s);
	// rra(s, NULL);
	// rra(s, NULL);
	// printstk(*s);
	// exit(1);
	int m=0;
	while (ft_entropy(*s) && m<5000)
	{
		// sleep(3);
		// ft_printf("\nMOVE(%d)\n", m);
		ft_direction(*s, &u);
		ft_set_indexes(s);
		ft_move(s, &u);
		ft_printf("\n");
		// printstk(*s);
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
	while (i < 3) // u.m len
	{
		// ft_printf("mfind%d_%d.", value, u.m[i]);
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
	// t_stack	*a;
	// t_stack	*b;

	ft_bzero(&u, sizeof(t_utils));
	ft_set_limits(*stk_a, &u);
	ft_printarr(u.m, 3);
	// ft_set_indexes(stk_a);
	ft_finalindex(stk_a, u);
	printstk(*stk_a);
	// exit(1);
	i = 0;
	while (i < u.size - 3) // u.m len
	{
		// ft_printf("test=%d(%d)\n", (*stk_a)->data->val, ft_mfind((*stk_a)->data->val, u));
		// ft_printarr(u.m, 3);
		if (!ft_mfind((*stk_a)->data->val, u))
		{
			pb(stk_a, stk_b);
			// exit(1);
			i++;
		}
		else
			ra(stk_a, stk_b);
	}
	// ft_printf("===separated====\n");
	// a = *stk_a;
	// b = *stk_b;
	// ft_printf("_a_\n");
	// printstk(*stk_a);
	// sa(&a, &b);
	// rra(stk_a, stk_b);
	ft_sortstack(stk_a);
	// ft_set_indexes(stk_a);
	/* ft_printf("_a_\n");
	printstk(*stk_a);
	ft_printf("_b_\n");
	printstk(*stk_b);
	ft_printf("\n"); */
	// exit(1);
	// a = *stk_a;
	// b = *stk_b;
	int count=0;
	/* ft_printf("===sorted====");
	ft_printf("size=%d\n", ft_stksize(*stk_a)); */
	i = 0;
	// while (ft_stksize(*stk_a) < u.size && count < 500000)
	while (i < u.size - 3 && count < 30)
	{
		ft_printf("%d/", i);
		ft_printf("((%d)t%d==t%d(%d))", (*stk_a)->data->val, (*stk_a)->data->final, (*stk_b)->data->final + 1, (*stk_b)->data->val);
		// if ((*stk_a)->data->final == (*stk_b)->data->final + 1)
		// {
		// 	pa(stk_a, stk_b);
		// 	i++;
		// }
		// else
		// 	ra(stk_a, stk_b);
		if ((*stk_a)->data->final == ft_stkindex((*stk_b)->data->final + 1, u.size))
		{
			pa(stk_a, stk_b);
			i++;
		}
		else
			rb(stk_a, stk_b);
		/* ft_printf("_a_\n");
		printstk(*stk_a);
		ft_printf("_b_\n");
		printstk(*stk_b);
		ft_printf("\n"); */
		count++;
		// if (count == 6)
		// 	exit(1);
	}
	// exit(1);
	ft_sortstack(stk_a);
	/* ft_printf("_a_\n");
	printstk(*stk_a);
	ft_printf("_b_\n");
	printstk(*stk_b);
	ft_printf("\n");
	// exit(1); */
}
