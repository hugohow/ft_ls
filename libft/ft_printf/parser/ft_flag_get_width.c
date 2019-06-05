/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_get_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:39:46 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/31 12:25:37 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_flag_get_width(char *str)
{
	long long		width;
	int				i;

	i = 0;
	width = 0;
	while (str[i])
	{
		if (str[i] == '.')
			break ;
		if (ft_isdigit(str[i]) == 1 && str[i] != '0')
		{
			while (str[i] && ft_isdigit(str[i]) == 1)
			{
				width = width * 10 + (str[i] - '0');
				i++;
			}
			if (width > 2147483647)
				return (0);
			return ((int)width);
		}
		i++;
	}
	return (width);
}
