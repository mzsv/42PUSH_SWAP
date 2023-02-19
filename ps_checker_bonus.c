/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:31:00 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/19 04:01:17 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker_bonus.h"

void	ft_error(char *msg)
{
	if (!msg)
		exit(1);
	ft_printf("%s\n", msg);
	exit(1);
}

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

	if (argc < 3)
		exit(1);
	if (!ft_check_input(argc, argv))
		ft_error("Error");
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
