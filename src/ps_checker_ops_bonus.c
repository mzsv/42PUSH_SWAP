/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_ops_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:14:14 by amenses-          #+#    #+#             */
/*   Updated: 2024/08/01 23:01:58 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps_bonus.h"

void	ft_freecatalog(char **catalog)
{
	int	i;

	i = 0;
	while (catalog[i])
	{
		free(catalog[i]);
		i++;
	}
	free(catalog);
}

int	ft_opcheck(char *op)
{
	char	**c;
	int		i;
	int		size;

	size = ft_strlen(op) + 1;
	c = ft_split("ra\n rb\n rr\n rra\n rrb\n rrr\n pa\n pb\n sa\n sb\n ss\n", \
		' ');
	i = 0;
	while (c[i])
	{
		if (ft_strncmp(op, c[i], size) == 0)
			break ;
		i++;
	}
	ft_freecatalog(c);
	if (i < 11)
		return (1);
	return (0);
}

t_ops	*ft_readops(t_stack **stk)
{
	t_ops	*ops;
	char	*tmp;

	ops = NULL;
	while (1)
	{
		tmp = get_next_line(0);
		if (!tmp)
			break ;
		if (!ft_opcheck(tmp))
		{
			free(tmp);
			ft_term_checker("Error", stk, &ops);
		}
		ft_opsadd_last(&ops, ft_opsnew(tmp));
		free(tmp);
	}
	return (ops);
}

void	ft_testops(t_stack **stk_a, t_ops *ops)
{
	t_stack	*stk_b;

	stk_b = NULL;
	while (ops)
	{
		ft_employop(stk_a, &stk_b, ops->op, 0);
		ops = ops->next;
	}
	if (stk_b)
		ft_stkclear(&stk_b);
}
