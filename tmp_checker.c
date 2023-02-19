/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:08:48 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/19 01:16:14 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker_bonus.h"

void	printops(t_ops *ops)
{
	while (ops)
	{
		ft_printf("%s\n", ops->op);
		ops = ops->next;
	}
}

void	printfstrs(char **strs)
{
	int i;
	
	i = 0;
	while (strs[i])
	{
		ft_printf(".%s.", strs[i]);
		i++;
	}
}

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
		ft_printf("s%d(%d)(tmp%d)(t%d)(f%d)\n", stk->data->val, stk->data->dist, stk->data->tmp_index, stk->data->target_index, stk->data->final);
		stk = stk->next;
	}
	stk = t;
}