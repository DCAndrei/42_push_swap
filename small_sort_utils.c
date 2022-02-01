/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:25:34 by acretu            #+#    #+#             */
/*   Updated: 2022/01/24 22:12:46 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_find_max(t_list *lst)
{
	int		max;
	t_list	*max_pos;
	t_list	*start;

	max = lst->nb;
	max_pos = lst;
	start = lst;
	lst = lst->next;
	while (lst != start)
	{
		if (max < lst->nb)
		{
			max = lst->nb;
			max_pos = lst;
		}
		lst = lst->next;
	}
	return (max_pos);
}

void	ft_small_sort_reverse(t_list **lst)
{
	t_list	*max;

	if (lst == NULL)
		exit (EXIT_FAILURE);
	max = ft_find_max(*lst);
	while (ft_check_reverse(*lst) != 1)
	{
		if ((*lst)->nb < (*lst)->next->nb && (*lst)->nb != max->nb)
			ft_sa_move(lst);
		else
			ft_ra_move(lst);
	}
	ft_help_small_sort_reverse(lst);
}

void	ft_help_small_sort_reverse(t_list **lst)
{
	int		n;

	if (*lst != ft_find_max(*lst))
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

int	ft_get_position_max(t_list *lst)
{
	t_list	*elem;
	int		n_ra;
	int		n_rra;

	elem = ft_find_max(lst);
	n_rra = 0;
	while (elem != lst)
	{
		n_rra++;
		elem = elem->next;
	}
	elem = ft_find_max(lst);
	n_ra = 0;
	while (elem != lst)
	{
		n_ra++;
		elem = elem->prev;
	}
	if (n_ra < n_rra)
		return (n_ra);
	else
		return (-n_rra);
}

int	ft_check_reverse(t_list *lst)
{
	t_list		*elem;
	t_list		*start;

	if (lst == NULL)
		return (-1);
	elem = ft_find_max(lst);
	if (elem != lst)
		return (0);
	start = elem;
	while (elem->next != start && elem->nb > elem->next->nb)
		elem = elem->next;
	if (elem->nb < elem->next->nb && elem->next == start)
		elem = elem->next;
	if (elem == start)
		return (1);
	else
		return (0);
}
