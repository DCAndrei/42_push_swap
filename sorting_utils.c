/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:04:44 by acretu            #+#    #+#             */
/*   Updated: 2022/01/23 00:32:44 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_to_b(t_list **a, t_list **b, int moves)
{
	while (moves > 0)
	{
		ft_push_b(a, b);
		moves--;
	}
	ft_small_sort_reverse(b);
}

void	ft_go_to_min(t_list **lst)
{
	int		n;

	if (*lst != ft_find_min(*lst))
	{
		n = ft_get_position(*lst);
		if (n < 0)
		{
			n = -n;
			while (n > 0)
			{
				ft_rra_move(lst);
				n--;
			}
		}
		else
		{
			while (n > 0)
			{
				ft_ra_move(lst);
				n--;
			}
		}
	}
}
