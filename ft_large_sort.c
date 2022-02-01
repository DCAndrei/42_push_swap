/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_large_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:18:34 by acretu            #+#    #+#             */
/*   Updated: 2022/01/26 16:58:36 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//v[0] is a counter j
//v[1] is the size of the initial stack
//v[2] is the nr of pivots

#include "push_swap.h"

void	ft_maxi_sort(t_list **lst)
{
	t_list	*b;
	int		*pivots;
	int		*total_elem_b;

	b = NULL;
	pivots = NULL;
	total_elem_b = NULL;
	ft_large_sort(lst, &b, &pivots, &total_elem_b);
	free(pivots);
	free(total_elem_b);
}

void	ft_large_sort(t_list **l, t_list **b, int **p, int **tb)
{
	int		*array;
	int		v[3];

	ft_init_array(l, &v[1], &array);
	ft_create_pivots_array(v[1], p, tb, &v[2]);
	ft_complete_pivots(array, p, v[1], v[2]);
	ft_complete_total_elem(tb, v[2], v[1]);
	v[0] = 0;
	while (v[0]++ < v[2])
	{
		if (v[0] -1 == 0)
		{
			(*tb)[v[0] -1] = ft_f_b_p(l, b, (*p)[v[0] -1], (*tb)[v[0] -1]);
			(*tb)[v[0] -1] = ft_pushb(l, b, (*p)[v[0] -1], (*tb)[v[0] -1]);
			ft_move_b_to_a(l, b, (*p)[v[0] -1]);
		}
		else
		{
			while ((*l)->nb > array[0] && (*tb)[v[0] -1] > 0)
				(*tb)[v[0] -1] = ft_sb(l, b, (*p)[v[0] -1], (*tb)[v[0] -1]);
			ft_iteration(l, b, (*p)[v[0] -1], (*p)[v[0] -1]);
		}
	}
	ft_help_last_push(l, b, array[0], v[0]);
	free (array);
}

void	ft_handle_b_stack_min(t_list **b, t_list **lst)
{
	int		position;
	int		pushed;

	pushed = 0;
	while (*b != NULL)
	{
		position = ft_get_position(*b);
		if (position < 0)
		{
			while (position != 0)
			{
				ft_rrb_move(b);
				position += 1;
			}
		}
		else
			ft_help_stack_min(&position, &pushed, lst, b);
		if (pushed == 1)
			ft_ra_move(lst);
		ft_push_a(lst, b);
		pushed = 1;
		if (*b == NULL)
			ft_ra_move(lst);
	}
}

void	ft_help_stack_min(int *position, int *pushed, \
		t_list **lst, t_list **b)
{
	while (*position != 0)
	{
		if (*pushed == 1)
		{
			ft_rr_move(lst, b);
			*pushed = 0;
		}
		else
			ft_rb_move(b);
		*position -= 1;
	}
}

void	ft_handle_b_stack_max(t_list **b, t_list **lst)
{
	int		position;

	while (*b != NULL)
	{
		position = ft_get_position_max(*b);
		if (position < 0)
		{
			while (position != 0)
			{
				ft_rrb_move(b);
				position += 1;
			}
		}
		else
		{
			while (position != 0)
			{
				ft_rb_move(b);
				position -= 1;
			}
		}
		ft_push_a(lst, b);
	}
}
