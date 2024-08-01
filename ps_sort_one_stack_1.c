/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_one_stack_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:58:32 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/20 01:16:31 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_direction(t_stack *stk, t_utils *u)
{
	t_stack	*t;
	int		i[2];
	int		stop;

	t = stk;
	stop = 0;
	ft_bzero(&i, sizeof(int) * 2);
	i[0] = ft_downcheck(stk, u->m[0], u->m[2]);
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
		i[1] = ft_upcheck(stk, u->m[0], u->m[2]);
		if (i[0] <= i[1] + 2)
			u->direction = -1;
		else
			u->direction = 1;
	}
	stk = t;
}

void	ft_rotate(t_stack **stk, t_utils *u)
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

void	ft_move(t_stack **s, t_utils *u)
{
	t_stack	*stk;

	ft_set_scores(s, u);
	stk = *s;
	if (stk->data->val > stk->next->data->val && \
		(stk->data->val != u->m[2] || stk->next->data->val != u->m[0]))
	{
		ft_employop(s, NULL, "sa\n", 1);
		u->decision = 2;
	}
	else
		ft_rotate(s, u);
	ft_set_indexes(s);
	stk = *s;
}

void	ft_sortstack(t_stack **s)
{
	t_stack	*stk;
	t_utils	u;

	stk = *s;
	ft_bzero(&u, sizeof(t_utils));
	ft_set_limits(stk, &u);
	ft_set_indexes(s);
	while (ft_entropy(*s))
	{
		ft_direction(*s, &u);
		ft_set_indexes(s);
		ft_move(s, &u);
	}
}
