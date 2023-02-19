/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:57:54 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/19 04:01:45 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker_bonus.h"

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

int		ft_opssize(t_ops *o)
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

void	ft_employop(t_stack **stk_a, t_stack **stk_b, char *op)
{
	if (!ft_strncmp(op, "ra\n", ft_strlen(op) + 1))
		ra(stk_a, stk_b);
	else if (!ft_strncmp(op, "rb\n", ft_strlen(op) + 1))
		rb(stk_a, stk_b);
	else if (!ft_strncmp(op, "rr\n", ft_strlen(op) + 1))
		rr(stk_a, stk_b);
	else if (!ft_strncmp(op, "rra\n", ft_strlen(op) + 1))
		rra(stk_a, stk_b);
	else if (!ft_strncmp(op, "rrb\n", ft_strlen(op) + 1))
		rrb(stk_a, stk_b);
	else if (!ft_strncmp(op, "rrr\n", ft_strlen(op) + 1))
		rrr(stk_a, stk_b);
	else if (!ft_strncmp(op, "pa\n", ft_strlen(op) + 1))
		pa(stk_a, stk_b);
	else if (!ft_strncmp(op, "pb\n", ft_strlen(op) + 1))
		pb(stk_a, stk_b);
	else if (!ft_strncmp(op, "sa\n", ft_strlen(op) + 1))
		sa(stk_a, stk_b);
	else if (!ft_strncmp(op, "sb\n", ft_strlen(op) + 1))
		sb(stk_a, stk_b);
	else if (!ft_strncmp(op, "ss\n", ft_strlen(op) + 1))
		ss(stk_a, stk_b);
}

void	ft_testops(t_stack **stk_a, t_ops *ops)
{
	t_stack	*stk_b;

	stk_b = NULL;
	while (ops)
	{
		ft_employop(stk_a, &stk_b, ops->op);
		ops = ops->next;
	}
	if (stk_b)
		ft_stkclear(&stk_b);
}
