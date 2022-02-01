/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_utils_four.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:44:37 by acretu            #+#    #+#             */
/*   Updated: 2022/01/26 16:54:52 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nr_moves_last(t_list *b)
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
	ret = ft_help_nr_moves_last(b, &moves, &list, nr_elem);
	free (moves);
	free (list);
	return (ret);
}

int	ft_help_nr_moves_last(t_list *b, int **moves, int **list, int nr_elem)
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
	i = (*moves)[nr_elem - 1];
	if (j <= i)
		return (1);
	else
		return (-1);
}

void	ft_help_last_push(t_list **l, t_list **b, int min, int count)
{
	if (count == 1)
		ft_last_push_b(l, b, min);
	else
		ft_last_push_b(l, b, min);
}
