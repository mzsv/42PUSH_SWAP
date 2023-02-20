/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:22:12 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/19 22:24:01 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_error(char *msg)
{
	if (!msg)
		exit(1);
	ft_printf("%s\n", msg);
	exit(1);
}

int	ft_check_input(int n, char **argv)
{
	int		i;
	char	*t;
	int		sign;

	i = 1;
	while (i < n)
	{
		t = argv[i];
		sign = 1;
		while (*t)
		{
			if (((*t == '-' || *t == '+') && sign) || (*t >= '0' && *t <= '9'))
			{
				sign = 0;
				t++;
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_dups(t_stack *stk)
{
	t_stack	*t;

	t = stk;
	while (t->next)
	{
		while (stk->next)
		{
			if (t->data->val == stk->next->data->val)
				return (0);
			stk = stk->next;
		}
		t = t->next;
		stk = t;
	}
	return (1);
}

int	ft_check_order(t_stack *stk)
{
	while (stk->next && (stk->data->val < stk->next->data->val))
		stk = stk->next;
	if (!stk->next)
		return (1);
	return (0);
}

t_stack	*ft_get_stack(int n, char **argv)
{
	t_stack		*a;
	long long	value;
	int			i;

	i = 1;
	value = 0;
	a = NULL;
	while (i < n)
	{
		value = ft_long_atoi(argv[i]);
		if (value > INTMAX || value < INTMIN)
		{
			ft_stkclear(&a);
			ft_error("Error");
		}
		ft_stkadd_last(&a, ft_stknew(value));
		i++;
	}
	return (a);
}
