/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:33:54 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/19 04:51:47 by amenses-         ###   ########.fr       */
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
		// sleep(1);
		ft_printf("s%d(%d)(tmp%d)(t%d)(f%d)\n", stk->data->val, stk->data->dist, stk->data->tmp_index, stk->data->target_index, stk->data->final);
		/* ft_printf("r=");
		ft_printarr(stk->data->pa_r, 3);
		ft_printf("rr=");
		ft_printarr(stk->data->pa_rr, 3);
		ft_printf("pa=");
		ft_printarr(stk->data->pa, 4); */
		// ft_printf("\n");
		// ft_printf("s%d(ra%d)(rb%d)(rr%d)\n", stk->data->val, stk->data->pa_r[0], stk->data->target_index, stk->data->final);
		// ft_printf("testprintstk=%d\n", stk->next == NULL);
		stk = stk->next;
	}
	stk = t;
}

void	printboth(t_stack *a, t_stack *b)
{
	ft_printf("_a_\n");
	printstk(a);
	ft_printf("_b_\n");
	printstk(b);
	ft_printf("\n");
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
	// printstk(*s);
	// rra(s, NULL);
	// rra(s, NULL);
	// printstk(*s);
	// exit(1);
	int m=0;
	while (ft_entropy(*s))
	{
		// sleep(3);
		// ft_printf("\nMOVE(%d)\n", m);
		ft_direction(*s, &u);
		ft_set_indexes(s);
		ft_move(s, &u);
		// ft_printf("\n");
		// printstk(*s);
		// ft_printf("entropy=%d\n", ft_entropy(a));
		// ft_printf("decision=%d\n", u.decision);
		// ft_direction(a, &u);
		// ft_printf("\n");
		m++;
	}
	// ft_printf("RESULT=%d\n", m);
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
			ft_printf("pb\n");
		}
		else
		{
			ra(stk_a, stk_b);
			ft_printf("ra\n");
		}
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

void	ft_pa_ra(t_stack *a, t_stack **stk_b, t_utils u)
{
	t_stack	*tb;
	t_stack	*ta;
	t_stack	*la;
	int		max_a;

	ta = a;
	tb = *stk_b;
	la = ft_stklast(a);
	max_a = ft_stkmax(a);
	ft_set_indexes(&a);
	while ((*stk_b))
	{
		if ((*stk_b)->data->final < a->data->final && ((*stk_b)->data->final > la->data->final || la->data->final == u.size - 1))
		{
			(*stk_b)->data->pa_r[0] = 0; // replace with continue for less lines of code
		}
		else
		{
			// ft_printf("here.");	
			while (a->next)
			{
				a = a->next;
				if ((*stk_b)->data->final < a->data->final && (*stk_b)->data->final > a->previous->data->final)
				{
					(*stk_b)->data->pa_r[0] = a->data->tmp_index;
					break ;
				}
			}
			a = ta;
		}
		(*stk_b) = (*stk_b)->next;
	}
	*stk_b = tb;
}

void	ft_pa_costs(t_stack **stk_a, t_stack **stk_b, t_utils u)
{
	t_stack	*t;
	int		size_b;

	if (!*stk_b)
		return ;
	t = *stk_b;
	size_b = ft_stksize(*stk_b);
	ft_pa_ra(*stk_a, stk_b, u);
	ft_set_indexes(stk_b);
	while ((*stk_b))
	{
		(*stk_b)->data->pa_r[1] = (*stk_b)->data->tmp_index; // right index?
		(*stk_b)->data->pa_r[2] = ft_min((*stk_b)->data->pa_r[0], (*stk_b)->data->pa_r[1]);
		(*stk_b)->data->pa_rr[0] = ft_stksize(*stk_a) - (*stk_b)->data->pa_r[0];
		(*stk_b)->data->pa_rr[1] = size_b - (*stk_b)->data->pa_r[1];
		(*stk_b)->data->pa_rr[2] = ft_min((*stk_b)->data->pa_rr[0], (*stk_b)->data->pa_rr[1]);
		(*stk_b)->data->pa[0] = ft_max((*stk_b)->data->pa_r[0], (*stk_b)->data->pa_r[1]);
		(*stk_b)->data->pa[1] = (*stk_b)->data->pa_r[0] + (*stk_b)->data->pa_rr[1];
		(*stk_b)->data->pa[2] = (*stk_b)->data->pa_rr[0] + (*stk_b)->data->pa_r[1];
		(*stk_b)->data->pa[3] = ft_max((*stk_b)->data->pa_rr[0], (*stk_b)->data->pa_rr[1]);
		(*stk_b) = (*stk_b)->next;
	}
	*stk_b = t;
}

int	ft_findmin(int *arr, int nelem)
{
	int	i;
	int	r;
	
	i = 1;
	r = 0;
	while (i < nelem)
	{
		// ft_printf("(%d<%d)", arr[i], arr[r]);
		if (arr[i] < arr[r])
			r = i;
		i++;
	}
	return (r);
}

void	ft_setops(int *r_ops, int *rr_ops, int combo)
{
	if (combo == 0)
	{
		r_ops[0] -= r_ops[2];
		r_ops[1] -= r_ops[2];
		ft_bzero(rr_ops, sizeof(int) * 3);
	}
	if (combo == 1)
	{
		r_ops[1] = 0;
		r_ops[2] = 0;
		rr_ops[0] = 0;
		rr_ops[2] = 0;
	}
	if (combo == 2)
	{
		r_ops[0] = 0;
		r_ops[2] = 0;
		rr_ops[1] = 0;
		rr_ops[2] = 0;
	}
	if (combo == 3)
	{
		rr_ops[0] -= rr_ops[2];
		rr_ops[1] -= rr_ops[2];
		ft_bzero(r_ops, sizeof(int) * 3);
	}
}

void	ft_pa_decision(t_stack *b, t_utils *u)
{
	t_stack	*t;
	int		tmp;
	int		i;

	t = b;
	u->combo = ft_findmin(b->data->pa, 4);
	tmp = b->data->pa[u->combo];
	ft_arrcpy(u->r, b->data->pa_r, 3);
	ft_arrcpy(u->rr, b->data->pa_rr, 3);
	// ft_printf("(i=%d,minpa0=%d)", u->combo, b->data->pa[u->combo]);
	while (b->next && tmp > 1) // if 0 or 1, no changes
	{
		b = b->next;
		i = ft_findmin(b->data->pa, 4);
		// ft_printf("(val=%d,i=%d,minpa=%d)", b->data->val, i, b->data->pa[i]);
		if (b->data->pa[i] < tmp)
		{
			u->combo = i;
			tmp = b->data->pa[u->combo];
			ft_arrcpy(u->r, b->data->pa_r, 3);
			ft_arrcpy(u->rr, b->data->pa_rr, 3);
		}
	}
	ft_setops(u->r, u->rr, u->combo);
	// ft_printarr(u->r, 3);
	// exit(1);
	b = t;
}

void	ft_pb_move(t_stack **stk_a, t_stack **stk_b, t_utils u)
{
	int	i;

	i = 0;
	while (i < u.size - 3) // u.m len
	{
		// ft_printf("test=%d(%d)\n", (*stk_a)->data->val, ft_mfind((*stk_a)->data->val, u));
		// ft_printarr(u.m, 3);
		if (!ft_mfind((*stk_a)->data->val, u))
		{
			pb(stk_a, stk_b);
			ft_printf("pb\n");
			// exit(1);
			i++;
		}
		else
		{
			ra(stk_a, stk_b);
			ft_printf("ra\n");
		}
	}
}

void	ft_r_employops(t_stack **stk_a, t_stack **stk_b, int *r_ops)
{
	int	i;

	// apply ra
	i = 0;
	while (i < r_ops[0])
	{
		ra(stk_a, stk_b);
		ft_printf("ra\n");
		i++;
	}
	// apply rb
	i = 0;
	while (i < r_ops[1])
	{
		rb(stk_a, stk_b);
		ft_printf("rb\n");
		i++;
	}
	// apply rr
	i = 0;
	while (i < r_ops[2])
	{
		rr(stk_a, stk_b);
		ft_printf("rr\n");
		i++;
	}
}

void	ft_rr_employops(t_stack **stk_a, t_stack **stk_b, int *rr_ops)
{
	int	i;

	// apply rra
	i = 0;
	while (i < rr_ops[0])
	{
		rra(stk_a, stk_b);
		ft_printf("rra\n");
		i++;
	}
	// apply rrb
	i = 0;
	while (i < rr_ops[1])
	{
		rrb(stk_a, stk_b);
		ft_printf("rrb\n");
		i++;
	}
	// apply rrr
	i = 0;
	while (i < rr_ops[2])
	{
		rrr(stk_a, stk_b);
		ft_printf("rrr\n");
		i++;
	}
}

/* void	ft_pa_move(t_stack **stk_a, t_stack **stk_b)
{
	t_utils	u;
	int		i;

	ft_bzero(&u, sizeof(t_utils));
	ft_set_limits(*stk_a, &u);
	ft_finalindex(stk_a, u);
	ft_pb_move(stk_a, stk_b, u);
	ft_sortstack(stk_a);
	ft_pa_costs(stk_a, stk_b);
	ft_pa_decision(*stk_b, &u);
	ft_r_employops(stk_a, stk_b, u.r);
	ft_rr_employops(stk_a, stk_b, u.rr);
	pa(stk_a, stk_b);
} */

void	ft_n3sort(t_stack **stk_a, t_stack **stk_b)
{
	t_utils	u;
	int		i;
	t_stack	*last;
	// t_stack	*a;
	// t_stack	*b;
	ft_bzero(&u, sizeof(t_utils));
	ft_set_limits(*stk_a, &u);
	// ft_printarr(u.m, 3);
	// ft_set_indexes(stk_a);
	ft_finalindex(stk_a, u);
	i = 0;
	while (i < u.size - 3) // u.m len
	{
		// ft_printf("test=%d(%d)\n", (*stk_a)->data->val, ft_mfind((*stk_a)->data->val, u));
		// ft_printarr(u.m, 3);
		// if (!ft_mfind((*stk_a)->data->val, u) && i < u.size - 5)
		if (!ft_mfind((*stk_a)->data->val, u))
		{
			pb(stk_a, stk_b);
			ft_printf("pb\n");
			// exit(1);
			i++;
		}
		else
		{
			ra(stk_a, stk_b);
			ft_printf("ra\n");
		}
	}
	// ft_printf("===separated====\n");
	ft_sortstack(stk_a);
	// printstk(*stk_a);
	// exit(1);
	ft_pa_costs(stk_a, stk_b, u);
	// printboth(*stk_a, *stk_b);
	ft_pa_decision(*stk_b, &u);
	// printboth(*stk_a, *stk_b);
	int count=0;
	i = 0;
	while (*stk_b)
	{
		last = ft_stklast(*stk_a);
		// ft_printf("%d/", i);
		// ft_printf("((%d)f%d>f%d(%d))", (*stk_a)->data->val, (*stk_a)->data->final, (*stk_b)->data->final, (*stk_b)->data->val);
		if ((*stk_b)->data->final < (*stk_a)->data->final && ((*stk_b)->data->final > last->data->final || last->data->final == u.size - 1))
		// if (ft_stkindex((*stk_b)->data->final + 1, u.size) == (*stk_a)->data->final)
		{
			// ft_printf("=%d<<%d=", (*stk_b)->data->final, (*stk_a)->data->final);
			pa(stk_a, stk_b);
			ft_printf("pa\n");
			i++;
		}
		else
		{
			ft_pa_costs(stk_a, stk_b, u);
			ft_pa_decision(*stk_b, &u);
			ft_r_employops(stk_a, stk_b, u.r);
			ft_rr_employops(stk_a, stk_b, u.rr);
			pa(stk_a, stk_b);
			ft_printf("pa\n");
		}
		count++;
	}
	ft_sortstack(stk_a);
	/* ft_printf("_a_\n");
	printstk(*stk_a);
	ft_printf("_b_\n");
	printstk(*stk_b);
	ft_printf("\n");
	// exit(1); */
}

/* void	ft_n3sort(t_stack **stk_a, t_stack **stk_b)
{
	t_utils	u;
	int		i;
	t_stack	*last;
	// t_stack	*a;
	// t_stack	*b;
	ft_bzero(&u, sizeof(t_utils));
	ft_set_limits(*stk_a, &u);
	// ft_printarr(u.m, 3);
	// ft_set_indexes(stk_a);
	ft_finalindex(stk_a, u);
	i = 0;
	while (i < u.size - 3) // u.m len
	{
		// ft_printf("test=%d(%d)\n", (*stk_a)->data->val, ft_mfind((*stk_a)->data->val, u));
		// ft_printarr(u.m, 3);
		if (!ft_mfind((*stk_a)->data->val, u))
		{
			pb(stk_a, stk_b);
			ft_printf("pb\n");
			// exit(1);
			i++;
		}
		else
		{
			ra(stk_a, stk_b);
			ft_printf("ra\n");
		}
	}
	// ft_printf("===separated====\n");
	ft_sortstack(stk_a);
	// printstk(*stk_a);
	// exit(1);
	ft_pa_costs(stk_a, stk_b, u);
	// printboth(*stk_a, *stk_b);
	ft_pa_decision(*stk_b, &u);
	// printboth(*stk_a, *stk_b);
	int count=0;
	i = 0;
	while (*stk_b)
	{
		last = ft_stklast(*stk_a);
		// ft_printf("%d/", i);
		// ft_printf("((%d)f%d>f%d(%d))", (*stk_a)->data->val, (*stk_a)->data->final, (*stk_b)->data->final, (*stk_b)->data->val);
		if ((*stk_b)->data->final < (*stk_a)->data->final && ((*stk_b)->data->final > last->data->final || last->data->final == u.size - 1))
		// if (ft_stkindex((*stk_b)->data->final + 1, u.size) == (*stk_a)->data->final)
		{
			// ft_printf("=%d<<%d=", (*stk_b)->data->final, (*stk_a)->data->final);
			pa(stk_a, stk_b);
			ft_printf("pa\n");
			i++;
		}
		else
		{
			ft_pa_costs(stk_a, stk_b, u);
			ft_pa_decision(*stk_b, &u);
			ft_r_employops(stk_a, stk_b, u.r);
			ft_rr_employops(stk_a, stk_b, u.rr);
			pa(stk_a, stk_b);
			ft_printf("pa\n");
		}
		count++;
	}
	ft_sortstack(stk_a);
	
} */

/* ft_printf("_a_\n");
	printstk(*stk_a);
	ft_printf("_b_\n");
	printstk(*stk_b);
	ft_printf("\n");
	// exit(1); */