/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:14:48 by acretu            #+#    #+#             */
/*   Updated: 2022/01/26 14:56:23 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_main_check(int argc, char *argv[], t_list **start);

int	main(int argc, char *argv[])
{
	t_list	*start;

	start = NULL;
	ft_main_check(argc, argv, &start);
	if (ft_list_size(start) < 16)
		ft_small_sort(&start);
	else
		ft_maxi_sort(&start);
	while (start->next != start)
		ft_del_elem(&start);
	free (start);
	return (0);
}

static void	ft_main_check(int argc, char *argv[], t_list **start)
{
	int		check;

	check = ft_check_input(argc, argv);
	if (check == 1)
		exit (EXIT_FAILURE);
	else if (check == -1)
	{
		write(1, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
	*start = ft_init_stack(argc, argv);
	check = ft_second_check(start);
	if (check == 1)
		exit (EXIT_FAILURE);
	else if (check == -1)
	{
		write(1, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
}
