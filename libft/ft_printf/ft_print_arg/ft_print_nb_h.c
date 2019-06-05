/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb_h.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:19:21 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/04 20:14:17 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_print_nb_h(va_list *ap, t_flag *flag)
{
	char				*output;
	unsigned short		tmp;
	unsigned long long	tmp_val;
	size_t				size_allocation;
	int					sign;

	tmp = (unsigned short)va_arg(*ap, unsigned int);
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
