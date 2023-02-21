/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:18:28 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/20 21:55:45 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_BONUS_H
# define PS_BONUS_H
# include "libft/libft.h"
# include "ps.h"

typedef struct s_ops
{
	char			*op;
	struct s_ops	*next;
}	t_ops;

void	ft_freecatalog(char **catalog);

int		ft_opcheck(char *op);

t_ops	*ft_readops(t_stack **stk);

void	ft_testops(t_stack **stk_a, t_ops *ops);

t_ops	*ft_opsnew(char *op);

void	ft_opsadd_last(t_ops **ops, t_ops *new);

int		ft_opssize(t_ops *o);

void	ft_opsclear(t_ops **ops);

void	ft_term_checker(char *msg, t_stack **stk, t_ops **ops);

#endif