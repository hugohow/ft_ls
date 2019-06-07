/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_is_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 20:41:29 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/07 12:24:44 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_format_is_valid(const char *fo)
{
	int					i;
	int					ret;

	i = -1;
	while (fo[++i])
	{
		if (fo[i] == '%')
		{
			ret = (int)ft_flaglen(fo + i);
			if (ret == -1)
				return (0);
			i += ret;
		}
	}
	return (1);
}
