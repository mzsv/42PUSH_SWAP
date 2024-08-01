/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:16:16 by amenses-          #+#    #+#             */
/*   Updated: 2024/08/01 23:02:00 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps_bonus.h"

t_ops	*ft_opsnew(char *op)
{
	t_ops	*node;

	node = malloc(sizeof(t_ops));
	if (!node)
		return (NULL);
	node->op = ft_strdup(op);
	if (!node->op)
		return (NULL);
	node->next = NULL;
	return (node);
}

void	ft_opsadd_last(t_ops **ops, t_ops *new)
{
	t_ops	*t;

	if (!*ops)
	{
		*ops = new;
		new->next = NULL;
		return ;
	}
	t = *ops;
	while (t->next)
	{
		t = t->next;
	}
	t->next = new;
}

int	ft_opssize(t_ops *o)
{
	int	i;

	i = 0;
	while (o)
	{
		o = o->next;
		i++;
	}
	return (i);
}

void	ft_opsclear(t_ops **ops)
{
	t_ops	*t;

	if (!*ops)
		return ;
	t = *ops;
	while (t)
	{
		t = (*ops)->next;
		free((*ops)->op);
		free(*ops);
		*ops = t;
	}
	*ops = NULL;
}
