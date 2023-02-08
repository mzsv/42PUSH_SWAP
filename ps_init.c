/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:07:54 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/08 00:32:36 by amenses-         ###   ########.fr       */
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
			ft_error("Error"); // terminate
		ft_stkadd(&a, ft_stknew(value));
		i++;
	}
	return (a);
}
