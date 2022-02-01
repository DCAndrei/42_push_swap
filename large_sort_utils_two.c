/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_utils_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 00:13:18 by acretu            #+#    #+#             */
/*   Updated: 2022/01/26 16:52:04 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pushb(t_list **lst, t_list **b, int pivot, int elem_b)

{
	t_list	*start;

	start = *lst;
	while ((*lst)->next != start && elem_b > 0)
	{
		if ((*lst)->nb <= pivot)
		{
			ft_push_b(lst, b);
			elem_b -= 1;
		}
		else
		{
			if (*b != NULL && (*b)->nb > (*b)->prev->nb)
				ft_rr_move(lst, b);
			else
				ft_ra_move(lst);
		}
	}
	if ((*lst)->nb <= pivot)
	{
		ft_push_b(lst, b);
		elem_b -= 1;
	}
	return (elem_b);
}

void	ft_create_pivots_array(int size, int **p, int **total_elem_b, int *nb)
{
	if (size > 499)
		*nb = size / 71;
	else if (size >= 66)
		*nb = size / 33;
	else
		*nb = 1;
	*p = (int *)malloc(sizeof(int) * (*nb));
	if (*p == NULL)
		exit(EXIT_FAILURE);
	*total_elem_b = (int *)malloc(sizeof(int) * (*nb));
	if (*total_elem_b == NULL)
		exit(EXIT_FAILURE);
}

void	ft_complete_pivots(int *array, int **p, int size, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		(*p)[i] = array[i * ((size / (nb + 1)) + 1) + size / (nb + 1) - 1];
		i++;
	}
}

void	ft_complete_total_elem(int **total, int nb, int size)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while (i < nb)
	{
		(*total)[i] = i * ((size / (nb + 1)) + 1) + size / (nb + 1);
		if (i > 0)
		{
			sum += (*total)[i - 1];
			(*total)[i] = i * ((size / (nb + 1)) + 1) + size / (nb + 1) - sum;
		}
		i++;
	}
}

void	ft_last_push_b(t_list **lst, t_list **b, int min)
{
	while ((*lst)->nb > min)
		ft_push_b(lst, b);
	if (ft_nr_moves_last(*b) == 1)
	{
		ft_handle_b_stack_max(b, lst);
		while ((*lst)->nb != min)
			ft_ra_move(lst);
	}
	else
		ft_handle_b_stack_min(b, lst);
	while ((*lst)->nb > min)
		ft_ra_move(lst);
}
