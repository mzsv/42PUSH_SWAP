/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:07:54 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/07 01:30:38 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_check_input(char *argv)
{
	while (*argv)
	{
		if ((*argv >= '0' && *argv <= '9') || *argv == ' ')
			argv++;
		else
			return (0);
	}
	return (1);
}

t_stack	ft_get_stack(char *argv)
{
	t_stack	stack;
	
	stack.n = ft_atoi(argv);
	
	return (stack);
}