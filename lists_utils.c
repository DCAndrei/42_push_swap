/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:30:14 by acretu            #+#    #+#             */
/*   Updated: 2022/01/25 22:55:30 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int n)
{
	t_list		*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list) * 1);
	if (new_elem == NULL)
		return (NULL);
	new_elem->nb = n;
	new_elem->next = new_elem;
	new_elem->prev = new_elem;
	return (new_elem);
}

int	ft_add_elem(t_list **lst, t_list *elem)
{
	if (elem == NULL)
		return (0);
	if (*lst == NULL)
		*lst = elem;
	else
	{
		elem->prev = (*lst)->prev;
		elem->next = *lst;
		(*lst)->prev->next = elem;
		(*lst)->prev = elem;
	}
	return (1);
}

int	ft_del_elem(t_list **elem)
{
	t_list	*tmp;

	if (*elem == NULL)
		return (0);
	else
	{
		tmp = *elem;
		(*elem)->prev->next = (*elem)->next;
		(*elem)->next->prev = (*elem)->prev;
		(*elem) = tmp->next;
		free (tmp);
		return (1);
	}
}

int	ft_list_size(t_list *lst)
{
	int		size;
	t_list	*init;

	size = 1;
	init = lst->prev;
	while (lst != init)
	{
		size += 1;
		lst = lst->next;
	}
	return (size);
}
