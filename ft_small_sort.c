/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:20:43 by acretu            #+#    #+#             */
/*   Updated: 2022/01/26 13:39:02 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_list **lst);

void	ft_small_sort(t_list **lst)
{
	int		size;
	int		nb_elem;
	t_list	*b;

	b = NULL;
	size = ft_list_size(*lst);
	if (size == 2)
		ft_ra_move(lst);
	else if (size == 3)
	{
		ft_sort_3(lst);
	}
	else
	{
		nb_elem = size - 3;
		while (nb_elem != 0)
		{
			ft_go_to_min(lst);
			ft_push_b(lst, &b);
			nb_elem -= 1;
		}
		ft_sort_3(lst);
		while (b != NULL)
			ft_push_a(lst, &b);
	}
}

void	ft_sort_3(t_list **lst)
{
	if ((*lst)->nb < (*lst)->next->nb && (*lst)->next->nb < (*lst)->prev->nb)
		return ;
	if ((*lst)->nb < (*lst)->next->nb)
	{
		if ((*lst)->nb > (*lst)->prev->nb)
			ft_rra_move(lst);
		else
		{
			ft_ra_move(lst);
			ft_sa_move(lst);
			ft_rra_move(lst);
		}
	}
	else
	{
		if ((*lst)->nb < (*lst)->prev->nb)
			ft_sa_move(lst);
		else if ((*lst)->next->nb < (*lst)->prev->nb)
			ft_ra_move(lst);
		else
		{
			ft_sa_move(lst);
			ft_rra_move(lst);
		}
	}
}

int	ft_check(t_list *lst)
{
	t_list		*elem;
	t_list		*start;

	if (lst == NULL)
		exit (EXIT_FAILURE);
	elem = ft_find_min(lst);
	if (elem != lst)
		return (0);
	start = elem;
	while (elem->next != start && elem->nb < elem->next->nb)
		elem = elem->next;
	if (elem->nb > elem->next->nb)
		elem = elem->next;
	if (elem == start)
		return (1);
	else
		return (0);
}

t_list	*ft_find_min(t_list *lst)
{
	int		min;
	t_list	*min_pos;
	t_list	*start;

	min = lst->nb;
	min_pos = lst;
	start = lst;
	lst = lst->next;
	while (lst != start)
	{
		if (min > lst->nb)
		{
			min = lst->nb;
			min_pos = lst;
		}
		lst = lst->next;
	}
	return (min_pos);
}

int	ft_get_position(t_list *lst)
{
	t_list	*elem;
	int		n_ra;
	int		n_rra;

	elem = ft_find_min(lst);
	n_rra = 0;
	while (elem != lst)
	{
		n_rra++;
		elem = elem->next;
	}
	elem = ft_find_min(lst);
	n_ra = 0;
	while (elem != lst)
	{
		n_ra++;
		elem = elem->prev;
	}
	if (n_ra <= n_rra)
		return (n_ra);
	else
		return (-n_rra);
}
