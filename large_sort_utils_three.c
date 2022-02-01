/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_utils_three.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 00:18:33 by acretu            #+#    #+#             */
/*   Updated: 2022/01/25 20:40:30 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nr_moves(t_list *b)
{
	int		*moves;
	int		*list;
	int		nr_elem;
	int		ret;

	list = NULL;
	nr_elem = ft_list_size(b);
	moves = (int *)malloc(sizeof(int) * nr_elem);
	if (moves == NULL)
		exit (EXIT_FAILURE);
	ret = ft_help_nr_moves(b, &moves, &list, nr_elem);
	free (moves);
	free (list);
	return (ret);
}

int	ft_help_nr_moves(t_list *b, int **moves, int **list, int nr_elem)
{
	int		i;
	int		j;

	i = 0;
	while (i++ < nr_elem)
		(*moves)[i - 1] = 0;
	*list = ft_create_array(&b, &nr_elem);
	ft_complete_moves(*moves, *list, nr_elem);
	j = (*moves)[nr_elem - 1];
	i = 0;
	while (i++ < nr_elem)
		(*moves)[i - 1] = 0;
	free (*list);
	*list = ft_create_array(&b, &nr_elem);
	ft_complete_moves_max(*moves, *list, nr_elem);
	i = (*moves)[nr_elem - 1] / 2;
	if (j <= i)
		return (1);
	else
		return (-1);
}

void	ft_complete_moves(int *moves, int *list, int size)
{
	int		i;
	int		min_index;
	int		j;

	i = 0;
	while (i < size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (list[min_index] > list[j])
				min_index = j;
			j++;
		}
		if ((min_index - i) < (size - min_index))
			ft_add_to_array(moves, size, i, (min_index - i));
		else
			ft_add_to_array(moves, size, i, (size - min_index));
		ft_swap(&list[i], &list[min_index]);
		i++;
	}
}

void	ft_complete_moves_max(int *moves, int *list, int size)
{
	int		i;
	int		max_index;
	int		j;

	i = 0;
	while (i < size - 1)
	{
		max_index = i;
		j = i + 1;
		while (j < size)
		{
			if (list[max_index] < list[j])
				max_index = j;
			j++;
		}
		if ((max_index - i) < (size - max_index))
			ft_add_to_array(moves, size, i, (max_index - i));
		else
			ft_add_to_array(moves, size, i, (size - max_index));
		ft_swap(&list[i], &list[max_index]);
		i++;
	}
}

void	ft_add_to_array(int *array, int size, int position, int value)
{
	int		i;

	i = position;
	while (i < size)
	{
		array[i] += value + 1;
		i++;
	}
}
