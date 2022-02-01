/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_in_order.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:05:47 by acretu            #+#    #+#             */
/*   Updated: 2022/01/26 13:39:56 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//creates an array, is sorting it and checks if the elements of the list are
//on the right position in the array, and returns the number of numbers that
//are on the right position form the start

#include "push_swap.h"

int	ft_order(t_list	**lst)
{
	int		*array;
	int		size;
	int		i;
	t_list	*tmp;

	size = 0;
	array = ft_create_array(lst, &size);
	ft_bubble_sort(array, size);
	i = 0;
	tmp = *lst;
	while (tmp->nb == array[i] && i < size)
	{
		i++;
		tmp = tmp->next;
	}
	free (array);
	if (i != size)
		i++;
	return (i);
}

int	*ft_create_array(t_list	**lst, int *size)
{
	int		*array;
	int		i;
	t_list	*tmp;

	tmp = *lst;
	*size = 0;
	while (tmp->next != *lst)
	{
		(*size)++;
		tmp = tmp->next;
	}
	(*size)++;
	array = (int *)malloc(sizeof(int) * (*size));
	if (array == NULL)
		return (NULL);
	i = 0;
	tmp = *lst;
	while (tmp->next != (*lst))
	{
		array[i] = tmp->nb;
		i++;
		tmp = tmp->next;
	}
	array[i] = tmp->nb;
	return (array);
}

void	ft_bubble_sort(int *array, int size)
{
	int		i;
	int		bol;

	bol = 0;
	while (bol == 0)
	{
		bol = 1;
		i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				ft_swap(&array[i], &array[i + 1]);
				bol = 0;
			}
			i++;
		}
	}
}

void	ft_swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
