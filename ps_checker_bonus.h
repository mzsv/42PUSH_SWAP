/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:43:44 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/19 04:01:18 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CHECKER_BONUS_H
# define PS_CHECKER_BONUS_H
# include "libft/libft.h"
# include "ps.h"

typedef struct s_ops
{
	char			*op;
	struct s_ops	*next;
}	t_ops;

// ps_checker_utils
t_ops	*ft_opsnew(char *op);
void	ft_opsadd_last(t_ops **ops, t_ops *new);
int		ft_opssize(t_ops *o);
void	ft_opsclear(t_ops **ops);
t_ops	*ft_readops(t_stack **stk);
t_stack	*ft_get_stack(int n, char **argv);
void	ft_testops(t_stack **stk_a, t_ops *ops);

// tmp
void	printfstrs(char **strs);
void	printops(t_ops *ops);
void	printstk(t_stack *stk);

// main
void	ft_term_checker(char *msg, t_stack **stk, t_ops **ops);

#endif