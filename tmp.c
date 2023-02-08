/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:33:54 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/08 00:35:52 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	printstk(t_stack *stk)
{
	while (stk)
	{
		ft_printf("s%d\n", stk->val);
		stk = stk->next;
	}
}

int	ft_check_dups(t_stack *stk)
{
	t_stack	*t;

	t = stk;
	while (t->next)
	{
		while (stk->next)
		{
			// ft_printf("(value=%d, next=%d)", value, stk->next->val);
			if (t->val == stk->next->val)
				return (0);
			stk = stk->next;
		}
		t = t->next;
		stk = t;
	}
	return (1);
}
