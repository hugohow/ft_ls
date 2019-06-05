/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:59:51 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 11:18:29 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char						*ft_print_nb_l(va_list *ap, t_flag *flag)
{
	unsigned long		tmp;
	char				*output;
	unsigned long long	tmp_val;
	size_t				size_allocation;
	int					sign;

	tmp = (unsigned long)va_arg(*ap, unsigned long int);
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
