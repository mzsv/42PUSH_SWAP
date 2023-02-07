/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:04:43 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/07 01:26:29 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || ft_check_input(argv[1]) == 0)
		ft_error("Error");
	
	return (0);
}
