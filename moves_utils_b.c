/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:16:16 by acretu            #+#    #+#             */
/*   Updated: 2022/01/25 23:02:14 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb_move(t_list **lst)
{
	int		tmp;
	t_list	*elem;

	elem = *lst;
	tmp = elem->nb;
	elem->nb = elem->next->nb;
	elem->next->nb = tmp;
	write(1, "sb\n", 3);
}

void	ft_rb_move(t_list **start)
{
	*start = (*start)->next;
	write(1, "rb\n", 3);
}

void	ft_rrb_move(t_list **start)
{
	*start = (*start)->prev;
	write(1, "rrb\n", 4);
}

void	ft_push_a(t_list **a, t_list **b)
{
	t_list		*new;
	t_list		*tmp;

	write(1, "pa\n", 3);
	new = ft_lstnew((*b)->nb);
	tmp = (*a)->prev;
	tmp->next = new;
	new->prev = tmp;
	new->next = (*a);
	(*a)->prev = new;
	(*a) = (*a)->prev;
	if ((*b)->next != *b)
		ft_del_elem(b);
	else
	{
		ft_del_elem(b);
		*b = NULL;
	}
}

void	ft_rrr_move(t_list **a, t_list **b)
{
	*a = (*a)->prev;
	*b = (*b)->prev;
	write(1, "rrr\n", 4);
}
