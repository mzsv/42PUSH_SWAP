/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_two_stacks_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:17:02 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/20 02:50:19 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_pb_move(t_stack **stk_a, t_stack **stk_b, t_utils u)
{
	int	i;

	i = 0;
	while (i < u.size - 3)
	{
		if (!ft_mfind((*stk_a)->data->val, u))
		// if ((*stk_a)->data->val != u.m[0] && (*stk_a)->data->val != u.m[2])
		{
			ft_employop(stk_a, stk_b, "pb\n", 1);
			i++;
		}
		else
			ft_employop(stk_a, stk_b, "ra\n", 1);
	}
}

void	ft_movetoa(t_stack **stk_a, t_stack **stk_b, t_utils *u)
{
	int		i;
	t_stack	*last;

	i = 0;
	while (*stk_b)
	{
		last = ft_stklast(*stk_a);
		if ((*stk_b)->data->fi < (*stk_a)->data->fi && \
			((*stk_b)->data->fi > last->data->fi || \
			last->data->fi == u->size - 1))
		{
			ft_employop(stk_a, stk_b, "pa\n", 1);
			i++;
		}
		else
		{
			ft_pa_costs(stk_a, stk_b, *u);
			ft_pa_decision(*stk_b, u);
			ft_r_employops(stk_a, stk_b, u->r);
			ft_rr_employops(stk_a, stk_b, u->rr);
			ft_employop(stk_a, stk_b, "pa\n", 1);
		}
	}
}

void	ft_n3sort(t_stack **stk_a)
{
	t_utils	u;
	t_stack	*stk_b;

	ft_bzero(&u, sizeof(t_utils));
	stk_b = NULL;
	ft_set_limits(*stk_a, &u);
	ft_finalindex(stk_a, u);
	ft_pb_move(stk_a, &stk_b, u);
	if (ft_stksize(*stk_a) > 2) // depends on the ft_pb_move
		ft_sortstack(stk_a);
	ft_pa_costs(stk_a, &stk_b, u);
	ft_pa_decision(stk_b, &u);
	ft_movetoa(stk_a, &stk_b, &u);
	ft_sortstack(stk_a);
}
