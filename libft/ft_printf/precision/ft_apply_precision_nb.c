/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_precision_nb.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:11:14 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/30 22:18:19 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_apply_precision_nb(char *str, t_flag *flag, int sign)
{
	unsigned int	str_len;

	str_len = ft_strlen(str);
	if (sign == 0 && flag->precision == 0)
	{
		str = ft_strcpy(str, "");
		return (str);
	}
	if (flag->precision < 0)
		return (str);
	if (str_len == (unsigned int)flag->precision)
		return (str);
	if (ft_str_precision_count(str, 0) < flag->precision)
		return (ft_add_char(str, flag, '0'));
	return (str);
}
