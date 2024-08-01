/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:30:41 by amenses-          #+#    #+#             */
/*   Updated: 2024/08/01 23:04:43 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps.h"

void	ft_term_pushswap(char *msg, t_stack **stk)
{
	if (*stk)
		ft_stkclear(stk);
	ft_error(msg);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (!ft_check_input(argc, argv))
		ft_error("Error");
	if (argc < 3)
		exit(1);
	a = ft_get_stack(argc, argv);
	if (!ft_check_dups(a))
		ft_term_pushswap("Error", &a);
	if (ft_check_order(a))
		ft_term_pushswap(NULL, &a);
	if (ft_stksize(a) < 6)
		ft_sortstack(&a);
	else
		ft_n3sort(&a);
	ft_stkclear(&a);
	return (0);
}
