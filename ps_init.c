/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:07:54 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/19 03:42:56 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_check_input(int n, char **argv)
{
	int		i;
	char	*t;
	int		sign;

	i = 1;
	while (i < n)
	{
		t = argv[i];
		// if (!ft_strlen(t))
		// 	return (0);
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
			// ft_printf("(value=%d, next=%d)", t->val, stk->next->val);
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
	// ft_printf("testcheckorder=%d\n", stk->next == NULL);
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

/* t_stack	*ft_get_stack(int n, char **argv)
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
			ft_error("Error"); // terminate
		ft_stkadd_last(&a, ft_stknew(value));
		i++;
	}
	return (a);
} */
