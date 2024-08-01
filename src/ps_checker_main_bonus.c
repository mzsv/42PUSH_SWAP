/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_main_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:20:45 by amenses-          #+#    #+#             */
/*   Updated: 2024/08/01 23:01:52 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps_bonus.h"

void	ft_term_checker(char *msg, t_stack **stk, t_ops **ops)
{
	if (*stk)
		ft_stkclear(stk);
	if (ops && *ops)
		ft_opsclear(ops);
	ft_error(msg);
}

int	main(int argc, char **argv)
{
	t_ops	*ops;
	t_stack	*stk;

	if (!ft_check_input(argc, argv))
		ft_error("Error");
	if (argc < 3)
		exit(1);
	stk = ft_get_stack(argc, argv);
	if (!ft_check_dups(stk))
		ft_term_checker("Error", &stk, NULL);
	ops = ft_readops(&stk);
	ft_testops(&stk, ops);
	if (ft_check_order(stk))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_stkclear(&stk);
	ft_opsclear(&ops);
	return (0);
}
