/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_get_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:39:46 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/11 13:34:22 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_apply_wildcard(va_list *ap, t_flag *flag)
{
	long long width;

	width = (long long)va_arg(*ap, int);
	if (width > 2147483647)
		return (0);
	if (width == 0)
	{
		flag->zero = 1;
		return (0);
	}
	if (width < 0)
	{
		flag->minus = 1;
		return ((int)(-1 * width));
	}
	return ((int)width);
}

static int			ft_get_width(char *str, int i, int wild, long long width_w)
{
	long long		width;

	width = 0;
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		width = width * 10 + (str[i] - '0');
		i++;
	}
	if (wild)
		width = width > width_w ? width_w : width;
	if (width > 2147483647)
		return (0);
	return ((int)width);
}

int					ft_flag_get_width(char *str, va_list *ap, t_flag *flag)
{
	long long		width;
	long long		width_wildcard;
	int				i;
	int				wild;

	i = 0;
	width = 0;
	width_wildcard = 0;
	wild = 0;
	while (str[i])
	{
		if (str[i] == '.')
			break ;
		if (str[i] == '*')
		{
			width_wildcard = ft_apply_wildcard(ap, flag);
			wild = 1;
		}
		else if (ft_isdigit(str[i]) == 1 && str[i] != '0')
			return (ft_get_width(str, i, wild, width_wildcard));
		i++;
	}
	return (width_wildcard);
}
