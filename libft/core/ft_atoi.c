/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 19:35:55 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 11:28:04 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_escapable_ft_atoi(char c)
{
	return (c == '\t' || c == '\v' || c == '\f' || c == '\r'
		|| c == '\n' || c == ' ');
}

int			ft_atoi(const char *str)
{
	long long	result;
	int			i;
	int			sign;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && is_escapable_ft_atoi(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = str[i] == '-' ? -1 : 1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)result * sign);
}
