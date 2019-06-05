/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:08:58 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 11:18:34 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char						*ft_print_nb(va_list *ap, t_flag *flag)
{
	char				*output;
	unsigned int		tmp;
	unsigned long long	tmp_val;
	size_t				size_allocation;
	int					sign;

	tmp = va_arg(*ap, unsigned int);
	sign = tmp == 0 ? 0 : 1;
	tmp_val = (unsigned long long)tmp;
	size_allocation = ft_nblen_ull(tmp_val);
	size_allocation = ft_len_to_alloc(size_allocation, flag);
	output = ft_ulltoa_offset(tmp_val, size_allocation);
	output = ft_convert_output(output, flag);
	output = ft_apply_precision_nb(output, flag, sign);
	output = ft_apply_padding_nb(output, flag, sign);
	return (output);
}
