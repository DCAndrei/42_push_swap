/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:16:14 by acretu            #+#    #+#             */
/*   Updated: 2022/01/24 23:07:57 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_move(t_list **lst)
{
	int		tmp;
	t_list	*elem;

	elem = *lst;
	tmp = elem->nb;
	elem->nb = elem->next->nb;
	elem->next->nb = tmp;
	write(1, "sa\n", 3);
}

void	ft_ra_move(t_list **start)
{
	*start = (*start)->next;
	write(1, "ra\n", 3);
}

void	ft_rra_move(t_list **start)
{
	*start = (*start)->prev;
	write(1, "rra\n", 4);
}

void	ft_push_b(t_list **a, t_list **b)
{
	t_list		*new;

	write(1, "pb\n", 3);
	new = ft_lstnew((*a)->nb);
	ft_add_elem(b, new);
	ft_del_elem(a);
	(*b) = (*b)->prev;
}

void	ft_rr_move(t_list **a, t_list **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
	write(1, "rr\n", 3);
}
