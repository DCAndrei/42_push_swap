/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:08:33 by acretu            #+#    #+#             */
/*   Updated: 2022/01/23 00:47:49 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_int(char *str)
{
	long		ret;
	long		sign;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str += 1;
	}
	ret = 0;
	while (*str != '\0')
	{
		ret = ret * 10 + (*str - '0');
		str += 1;
	}
	ret *= sign;
	if (ret > INT_MAX || ret < INT_MIN)
		return (0);
	else
		return (1);
}
