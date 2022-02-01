/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:50:23 by acretu            #+#    #+#             */
/*   Updated: 2022/01/23 00:47:43 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_init_stack(int argc, char *argv[])
{
	t_list		*elem;
	t_list		*head;
	int			i;

	elem = NULL;
	i = 1;
	head = ft_lstnew(ft_atoi(argv[i]));
	i++;
	while (i < argc)
	{
		elem = ft_lstnew(ft_atoi(argv[i]));
		if (elem == NULL)
		{
			while (head != NULL)
				ft_del_elem(&head);
			exit(EXIT_FAILURE);
		}
		ft_add_elem(&head, elem);
		i++;
	}
	return (head);
}
