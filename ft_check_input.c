/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 20:06:11 by acretu            #+#    #+#             */
/*   Updated: 2022/01/04 20:55:40 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_input(int argc, char *argv[])
{
	int		i;

	i = 1;
	if (argc == 1)
		return (1);
	while (i < argc)
	{
		if (!ft_initial_check(argv[i]) || !ft_check_int(argv[i]))
			return (-1);
		i++;
	}
	return (0);
}
