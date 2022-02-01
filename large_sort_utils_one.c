/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_utils_one.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 00:10:37 by acretu            #+#    #+#             */
/*   Updated: 2022/01/25 20:57:22 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sb(t_list **lst, t_list **b, int pivot, int total)
{
	if ((*lst)->nb <= pivot)
	{
		ft_push_b(lst, b);
		total -= 1;
	}
	else
	{
		if (*b != NULL && (*b)->nb > (*b)->prev->nb)
			ft_rr_move(lst, b);
		else
			ft_ra_move(lst);
	}
	return (total);
}

void	ft_iteration(t_list **lst, t_list **b, int piv1, int piv0)
{
	while ((*lst)->prev->nb > piv1)
		ft_rra_move(lst);
	if (ft_nr_moves(*b) == 1)
	{
		ft_handle_b_stack_max(b, lst);
		while ((*lst)->nb <= piv0)
			ft_ra_move(lst);
	}
	else
		ft_handle_b_stack_min(b, lst);
}

int	ft_f_b_p(t_list **lst, t_list **b, int pivot, int total)
{
	while ((*lst)->nb <= pivot && total > 0)
	{
		ft_push_b(lst, b);
		total -= 1;
	}
	return (total);
}

void	ft_move_b_to_a(t_list **lst, t_list **b, int pivot)
{
	if (ft_nr_moves(*b) == 1)
	{
		ft_handle_b_stack_max(b, lst);
		while ((*lst)->nb <= pivot)
			ft_ra_move(lst);
	}
	else
		ft_handle_b_stack_min(b, lst);
}

void	ft_init_array(t_list **lst, int *size, int **array)
{
	*size = ft_list_size(*lst);
	*array = ft_create_array(lst, size);
	ft_bubble_sort(*array, *size);
}
