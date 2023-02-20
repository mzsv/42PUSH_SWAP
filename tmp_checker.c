/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:08:48 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/20 00:14:47 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"

void	printops(t_ops *ops) // NA
{
	while (ops)
	{
		ft_printf("%s\n", ops->op);
		ops = ops->next;
	}
}

void	printfstrs(char **strs) // NA
{
	int i;
	
	i = 0;
	while (strs[i])
	{
		ft_printf(".%s.", strs[i]);
		i++;
	}
}

void	printstk(t_stack *stk) // NA
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
		ft_printf("s%d(%d)(tmp%d)(t%d)(f%d)\n", stk->data->val, stk->data->dist, stk->data->i, stk->data->target, stk->data->fi);
		stk = stk->next;
	}
	stk = t;
}