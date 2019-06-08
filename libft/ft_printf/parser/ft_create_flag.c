/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:11:26 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/08 14:37:07 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		*ft_create_flag(char *str)
{
	t_flag	*flag;

	if (ft_flag_get_key(str) == 0)
		return (NULL);
	if (!(flag = (t_flag *)ft_memalloc(sizeof(t_flag))))
		return (NULL);
	flag->key = ft_flag_get_key(str);
	flag->conv = str[ft_strlen(str) - 1];
	flag->length = ft_flag_get_length(str);
	flag->precision = ft_flag_get_precision(str);
	flag->width = ft_flag_get_width(str);
	flag->minus = ft_flag_get_minus(str);
	if (flag->minus == 1)
		flag->zero = 0;
	else
		flag->zero = ft_flag_get_zero(str);
	flag->plus = ft_flag_get_plus(str);
	flag->space = ft_flag_get_space(str);
	flag->hash = ft_flag_get_hash(str);
	flag->character = -1;
	flag->character_i = -1;
	flag->size_allocation = 0;
	return (flag);
}
