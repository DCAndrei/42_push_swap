/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:25:26 by acretu            #+#    #+#             */
/*   Updated: 2022/01/23 00:31:50 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int		sign;
	int		nb;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	nb = 0;
	while (*str != '\0')
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return (sign * nb);
}
