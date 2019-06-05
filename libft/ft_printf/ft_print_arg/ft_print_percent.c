/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:05:59 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/04 01:15:10 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_print_percent(va_list *ap, t_flag *flag)
{
	char	*output;

	(void)ap;
	(void)flag;
	output = ft_strdup(PERCENTAGE);
	if (flag->precision != 0)
		output = ft_apply_precision_str(output, flag, 1);
	output = ft_apply_padding_str(output, flag, 1);
	return (output);
}
