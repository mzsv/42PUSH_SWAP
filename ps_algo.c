/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:56:39 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/19 23:02:38 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	*ft_stktoarr(t_stack *stk, int size) // stacks1
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

int	*ft_arrsort(int *arr, int size) // utils
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

/* t_stack	*ft_stksort(t_stack *stk) // NA
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
} */

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

/* int		ft_stkfind(t_stack *stk, int value) // NA
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

int	ft_arrfind(int *arr, int value, int size) // utils
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

void	ft_finalindex(t_stack **s, t_utils u) // sort_twostacks_0
{
	int		*sorted;
	t_stack	*t;

	if (!*s)
		return ;
	t = *s;
	sorted = ft_stktoarr((*s), u.size);
	sorted = ft_arrsort(sorted, u.size);
	while ((*s))
	{
		(*s)->data->fi = ft_arrfind(sorted, (*s)->data->val, u.size);
		// ft_printf("fi=%d\n", (*s)->data->fi);
		(*s) = (*s)->next;
	}
	*s = t;
	free(sorted);
}

void	ft_set_indexes(t_stack **stk) // sort_onestack
{
	t_stack	*t;
	int		i;
	int		*sorted;
	int		size;

	if (!*stk)
		return ;
	t = *stk;
	size = ft_stksize(t);
	// ft_printf("size=%d\n", size);
	sorted = ft_stktoarr(t, size);
	sorted = ft_arrsort(sorted, size);
	// ft_printf("sorted: ");
	// ft_printarr(sorted, size);
	// ft_printf("instk: ");
	// printstk(t);
	i = 0;
	while (t)
	{
		// ft_printf("i=%d, ", i);
		t->data->target = ft_arrfind(sorted, t->data->val, size);
		// ft_printf("test=%d\n", t->data->target);
		// ft_printf("test=%d\n", t->data->val);
		// ft_printf("testindex=%d\n", t->data->target);
		t->data->i = i;
		// t->data->dist = t->data->target - t->data->i;
		// t->data->dist = ft_idist(t->data->i, t->data->target, size);
		t->data->dist = ft_indexdist(t->data->i, t->data->target, size);
		// t->data->dist = ft_minabs(t->data->dist, - size + (t->data->target - (t->data->i + 1)));
		// ft_printf("[%d-%d]=%d", t->data->target, t->data->i, t->data->dist);
		// t->data->dir = ft_sign(t->data->dist);
		// if (t->data->dist)
		// ft_printf("test=%d\n", t->data->dist);
		t = t->next;
		i++;
	}
	free(sorted);
}

/* int	ft_minabs(int a, int b) // NA
{
	if (ft_abs(a) <= ft_abs(b))
		return (a);
	return (b);
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

int	ft_entropy(t_stack *stk) // sort_one_stack
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

int	ft_stkindex(int index, int size) // sort_one_stack
{
	if (index < 0)
		return(size - (ft_abs(index) % size));
	if (index > size - 1)
		return (index % size);
	return (index);
}

/* int	ft_idist(int ci, int ti, int size) // NA
{
	ci = ft_stkindex(ci, size);
	// return (ft_minabs(ti - ci, - size + (ti - (ci + 1))));
	return (ft_minabs(ti - ci, - ((ti + ci + 1) % (size - 1))));
} */

void	ft_set_scores(t_stack **s, t_utils *u) // sort_one_stack
{
	t_stack	*t;
	t_stack	*stk;

	stk = *s;
	t = stk;
	u->ra = 0;
	u->rra = 0;
	while (stk)
	{
		stk->data->r = ft_indexdist(ft_stkindex(stk->data->i - 1, u->size), \
			stk->data->target, u->size);
		u->ra += ft_abs(stk->data->r);
		stk->data->rr = ft_indexdist(ft_stkindex(stk->data->i + 1, u->size), \
			stk->data->target, u->size);
		u->rra += ft_abs(stk->data->rr);
		stk = stk->next;
	}
	stk = t;
}

/* void	ft_set_scores(t_stack **s)
{
	t_stack	*t;
	t_stack	*stk;
	int		size;

	size = ft_stksize(*s);
	stk = *s;
	t = stk;
	while (stk)
	{
		// ft_printf("stk_pos=%d\n", stk->data->i);
		stk->data->s = stk->data->dist;
		// ft_printf("ra=(%d-%dto%d)%d->", stk->data->target, stk->data->i, ft_stkindex(stk->data->i - 1, size), stk->data->r);
		stk->data->r = ft_indexdist(ft_stkindex(stk->data->i - 1, size), stk->data->target, size);
		// ft_printf("%d | ", stk->data->r);
		// ft_printf("rr=(%d-%d)%d->", stk->data->target, ft_stkindex(stk->data->i + 1, size), stk->data->rr);
		stk->data->rr = ft_indexdist(ft_stkindex(stk->data->i + 1, size), stk->data->target, size);
		// ft_printf("%d", stk->data->rr);
		// ft_printf("\n");
		stk = stk->next;
	}
	stk = t;
	stk->data->s = ft_indexdist(ft_stkindex(stk->data->i + 1, size), stk->data->target, size);
	stk->next->data->s = ft_indexdist(ft_stkindex(stk->data->i - 1, size), stk->data->target, size);
	if((stk->data->val == ft_stkmax(stk) && stk->next->data->val == ft_stkmin(stk)) || (stk->data->val < stk->next->data->val))
		stk->data->s = size;
	// ft_upscore(s);
} */

int	ft_stkmax(t_stack *stk) // stacks1
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

int	ft_stkmin(t_stack *stk) // stacks1
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

int	ft_downcheck(t_stack *stk, int min, int max) // sort_one_stack_1
{
	int	i;
	int	stop;

	i = 0;
	stop = 0;
	while (stk->next)
	{
		if (!stop && !(stk->data->val > stk->next->data->val && \
			(stk->data->val != max || stk->next->data->val != min)))
			i++;
		else
			stop = 1;
		stk = stk->next;
	}
	return (i);
}

int	ft_upcheck(t_stack *stk, int min, int max) // sort_one_stack_1
{
	int	i;
	int	stop;

	i = 0;
	stop = 0;
	// stk = ft_stklast(stk);
	while (stk->prev)
	{
		if (!stop && !(stk->data->val < stk->prev->data->val && \
			(stk->data->val != min || stk->prev->data->val != max)))
			i++;
		else
			stop = 1;
		stk = stk->prev;
	}
	return (i);
}

void	ft_direction(t_stack *stk, t_utils *u) // sort_one_stack_1
{
	t_stack	*t;
	int		i[2];
	int		stop;

	t = stk;
	stop = 0;
	ft_bzero(&i, sizeof(int) * 2);
	i[0] = ft_downcheck(stk, u->m[0], u->m[2]);
	/* while (stk->next)
	{
		if (!stop && !(stk->data->val > stk->next->data->val && \
			(stk->data->val != u->m[2] || stk->next->data->val != u->m[0])))
			i[0]++;
		else
			stop = 1;
		stk = stk->next;
	} */
	stk = ft_stklast(stk);
	if (!i[0])
		u->direction = 0;
	else if (stk->data->val > t->data->val && \
		(stk->data->val != u->m[2] || t->data->val != u->m[0]))
		u->direction = 1;
	else if (i[0] == u->size - 1)
		u->direction = 0;	
	else
	{
		/* stop = 0;
		while (stk->prev)
		{
			if (!stop && !(stk->data->val < stk->prev->data->val && \
				(stk->data->val != u->m[0] || stk->prev->data->val != u->m[2])))
				i[1]++;
			else
				stop = 1;
			stk = stk->prev;
		}
		stk = t; */
		i[1] = ft_upcheck(stk, u->m[0], u->m[2]);
		if (i[0] <= i[1] + 2)
			u->direction = -1;
		else
			u->direction = 1;
	}
	stk = t;
	// ft_printf("(direction=%d)", u->direction);
}

/* void	ft_direction(t_stack *stk, t_utils *u)
{
	t_stack	*t;
	int		i[2];
	int		stop;

	t = stk;
	stop = 0;
	ft_bzero(&i, sizeof(int) * 2);
	// u->direction = 0;
	while (stk->next)
	{
		if (!stop && !(stk->data->val > stk->next->data->val && (stk->data->val != ft_stkmax(t) || stk->next->data->val != ft_stkmin(t))))
		{	
			// ft_printf("test%d<%dmax=%d ", stk->data->val, stk->next->data->val, ft_stkmax(t));
			// ft_printf("(%d)(i0=%d)", stk->data->val, i[0]);
			i[0]++;
		}
		else
			stop = 1;
		stk = stk->next;
		// ft_printf("(%d)", stk->data->val);
	}
	ft_printf("(test_i0=%d)", i[0]);
	// ft_printf("(%d>%d)if yes RRA!//", stk->data->val, t->data->val);
	if (stk->data->val > t->data->val && (stk->data->val != ft_stkmax(t) || t->data->val != ft_stkmin(t)))
	{
		ft_printf("FAZ RRA!");
		u->direction = 1;
	}
	else
	{
		stop = 0;
		// rev_printstk(stk);
		while (stk->prev)
		{
			// ft_printf("test%d>%d ", stk->data->val, stk->prev->data->val);
			if (!stop && !(stk->data->val < stk->prev->data->val && (stk->data->val != ft_stkmin(t) || stk->prev->data->val != ft_stkmax(t))))
				i[1]++;
			else
				stop = 1;
			// ft_printf("(%d)", stk->data->val);
			stk = stk->prev;
		}
		ft_printf("(test_i1=%d)", i[1] + 2);
		stk = t;
		ft_printf("(size=%d)", u->size);
		// if (i[0] && (i[0] < u->size - 1) && (i[0] <= i[1] + 2))
		if (i[0] % (u->size - 1) && (i[0] <= i[1] + 2))
			u->direction = -1;
		else if (i[0] % (u->size - 1))
			u->direction = 1;
		else
			u->direction = 0;
	}
	stk = t;
	ft_printf("(test_direction=%d)", u->direction);
	// exit(1);
} */

void	ft_rotate(t_stack **stk, t_utils *u) // sort_one_stack_1
{
	if (u->direction == -1)
	{
		ft_employop(stk, NULL, "ra\n", 1);
		u->decision = 0;
	}
	else if (u->direction == 1)
	{
		ft_employop(stk, NULL, "rra\n", 1);
		u->decision = 1;
	}
	else
	{
		if (u->ra <= u->rra && u->decision != 1)
		{
			ft_employop(stk, NULL, "ra\n", 1);
			u->decision = 0;
		}
		else
		{
			ft_employop(stk, NULL, "rra\n", 1);
			u->decision = 1;
		}
	}
}

void	ft_move(t_stack **s, t_utils *u) // sort_one_stack_1
{
	// int	e[2];
	// t_stack	*t;
	t_stack *stk;
	// int	d;

	// ft_bzero(e, sizeof(int) * 2);
	ft_set_scores(s, u);
	stk = *s;
	if	(stk->data->val > stk->next->data->val && \
		(stk->data->val != u->m[2] || stk->next->data->val != u->m[0]))
	{
		ft_employop(s, NULL, "sa\n", 1);
		u->decision = 2;
		// sa(s, NULL);
		// ft_printf("sa\n");
		// d = 2;
	}
	else
		ft_rotate(s, u);
	/* {
		t = *s;
		// e[0] = u->ra;
		// e[1] = u->rra;
		if (u->direction == -1)
		{
			ra(s, NULL);
			ft_printf("ra\n");
			d = 0;
		}
		else if (u->direction == 1)
		{
			rra(s, NULL);
			ft_printf("rra\n");
			d = 1;
		}
		else
		{
			if (u->ra <= u->rra && u->decision != 1)
			{
				ra(s, NULL);
				ft_printf("ra\n");
				d = 0;
			}
			else
			{
				rra(s, NULL);
				ft_printf("rra\n");
				d = 1;
			}
		}
	}
	u->decision = d; */
	ft_set_indexes(s);
	stk = *s;
}

/* void	ft_move(t_stack **s, t_utils u)
{
	int	e[3];
	t_stack	*t;
	t_stack *stk;
	int	d;
	int	size;

	size = ft_stksize(*s);
	ft_bzero(e, sizeof(int) * 3);
	ft_set_scores(s);
	stk = *s;
	d = 100;
	// ft_printf("first2=%d,%d(s=%d)\n", stk->data->val, stk->next->data->val, stk->data->s);
	ft_printf("(test_direction_ftmove=%d)\n", u.direction);
	if	(stk->data->val > stk->next->data->val && stk->data->s < size)
	{
		ft_printf("========TEST===========\n");
		sa(s, NULL);
		d = 2;
	}
	else
	{
		t = *s;
		while (stk)
		{
			stk->data->dist = stk->data->r;
			stk = stk->next;
		}
		stk = t;
		e[0] = ft_entropy(stk);
		ft_printf("-entropy_ra=%d-\n", e[0]);
		while (stk)
		{
			stk->data->dist = stk->data->rr;
			stk = stk->next;
		}
		stk = t;
		e[1] = ft_entropy(stk);
		ft_printf("-entropy_rra=%d-\n", e[1]);
		while (stk)
		{
			if (e[0] <= e[1] && stk->data->decision != 1)
			{
				stk->data->dist = stk->data->r;
			}
			else
			{
				stk->data->dist = stk->data->rr;
			}
			stk = stk->next;
		}
		stk = t;
		while (stk)
		{
			stk->data->dist = stk->data->s;
			stk = stk->next;
		}
		stk = t;
		e[2] = ft_entropy(stk);
		ft_printf("-entropy_sa=%d-\n", e[2]);
		// ft_printf("(test=%d)", ft_stksize(stk));
		if (u.direction == -1)
		{
			ra(s, NULL);
			// stk->data->decision = 0;
			d = 0;
		}
		else if (u.direction == 1)
		{
			rra(s, NULL);
			// stk->data->decision = 0;
			d = 1;
		}
		else if ((e[0] <= e[2] || e[1] <= e[2]) || stk->data->decision == 2)
		{
			if (e[0] <= e[1] && stk->data->decision != 1)
			{
				ra(s, NULL);
				// stk->data->decision = 0;
				d = 0;
			}
			else
			{
				rra(s, NULL);
				// stk->data->decision = 1;
				d = 1;
			}
		}
		else
		{
			sa(s, NULL);
			// stk->data->decision = 2;
			d = 2;
		}
	}
	ft_set_indexes(s);
	stk = *s;
	// int z = 0;
	while (stk)
	{
		stk->data->decision = d;
		// ft_printf("dec_in=%d(%d)\n", stk->data->decision, z++);
		stk = stk->next;
	}
	stk = *s;
	// ft_printf("(test=%d)", ft_stksize(stk));
} */

/* void	ft_moveup(t_stack **s)
{
	t_stack	*t;
	t_stack	*stk;
	int		u;

	t = *s;
	stk = *s;
	while (stk)
	{
		if (stk->data->up[1])
		{
			ft_printf("========TEST 2==(%d)=========\n", stk->data->up[0]);
			u = 0;
			while (u < ft_abs(stk->data->up[0]))
			{
				ft_printf("(u=%d)", u);
				if (stk->data->up[0] < 0)
				{
					ra(s, NULL);
					ft_printf("ra\n");
				}
				else
				{
					rra(s, NULL);
					ft_printf("rra\n");
				}
				u++;
			}
		}
		stk = stk->next;
	}
	stk = t;
	
} */
