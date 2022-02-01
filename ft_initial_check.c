/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initial_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:43:16 by acretu            #+#    #+#             */
/*   Updated: 2022/01/23 00:47:34 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Checks if the arguments are all digits, if the number of digits are in the 
integer interval (does not check for the actual INT_MIN & INT_MAX), also
checks if numbers like -0, 00something are not present
*/

#include "push_swap.h"

static int	ft_isdigit(int ch);

int	ft_initial_check(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
		i += 1;
	while (ft_isdigit(str[i]))
		i += 1;
	if (str[i] != '\0')
		return (0);
	else if (str[0] == '-' && (i > 11 || str[1] == '0'))
		return (0);
	else if (str[0] != '-' && (i > 10 || (str[0] == str[1] && str[0] == '0')))
		return (0);
	return (1);
}

static int	ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}
