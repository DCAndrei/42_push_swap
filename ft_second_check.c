/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:39:40 by acretu            #+#    #+#             */
/*   Updated: 2022/01/26 17:45:40 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_second_check(t_list **lst)
{
	t_list		*start_pos;
	t_list		*tmp;

	start_pos = *lst;
	while ((*lst)->next != start_pos && (*lst)->nb < (*lst)->next->nb)
		(*lst) = (*lst)->next;
	if ((*lst)->next == start_pos)
		return (1);
	(*lst) = start_pos;
	while ((*lst)->next != start_pos)
	{
		tmp = (*lst)->next;
		while (tmp != start_pos)
		{
			if ((*lst)->nb == tmp->nb)
				return (-1);
			tmp = tmp->next;
		}
		(*lst) = (*lst)->next;
	}
	(*lst) = (*lst)->next;
	(*lst) = start_pos;
	return (0);
}
