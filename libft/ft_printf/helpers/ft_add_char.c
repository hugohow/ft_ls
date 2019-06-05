/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:06:37 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/31 12:14:23 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_add_element(char *str, t_flag *flag, int index, char c)
{
	if (flag->minus == 1 || (str[0] != ' '))
		return (ft_str_insert(str, c, index));
	else
	{
		ft_str_left_shift(str, index - 1);
		str[index] = c;
		return (str);
	}
}

static char		*add_one_char(char *str, t_flag *flag, char c)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || ft_isalpha(str[i]))
		{
			i += 0;
			return (ft_add_element(str, flag, i, c));
		}
		i++;
	}
	return (str);
}

char			*ft_add_char(char *str, t_flag *flag, char c)
{
	int			offset;

	offset = 0;
	if (ft_str_precision_count(str, offset) == flag->precision)
		return (str);
	str = add_one_char(str, flag, c);
	return (ft_add_char(str, flag, c));
}
