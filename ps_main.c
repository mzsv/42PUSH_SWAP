/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:04:43 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/09 01:52:50 by amenses-         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*t;

	if (argc < 3)
		exit(1);
	if (!ft_check_input(argc, argv))
		ft_error("Error: invalid");
	a = ft_get_stack(argc, argv);
	if (!ft_check_dups(a))
		ft_error("Error: checkdups"); // terminate
	// ft_printf("test=%d\n", ft_check_order(a));
	if (ft_check_order(a))
		exit(1);
	b = NULL;
	// ft_printf("%d\n", ft_stksize(a));
	// ft_printf("%d\n", ft_stksize(a));
	printstk(a);
	// ft_printf("\ntest=%d\n", ft_check_dups(a));
	// printstk(a);
	// sa(a, b);
	
	// ft_printf("weight=%d\n", 0);
	t = ft_sortstk_arr(a);
	ft_printarr(t, ft_stksize(a));
	// printstk(t);
	/* pb(&a, &b);
	pb(&a, &b);
	rrr(&a, &b);
	ft_printf("\na\n");
	printstk(a);
	ft_printf("\nb\n");
	printstk(b); */
	return (0);
}
