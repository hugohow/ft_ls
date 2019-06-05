/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:53:57 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 11:18:22 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_print_d(va_list *ap, t_flag *flag)
{
	char				*output;
	unsigned long long	tmp_val;
	size_t				size_allocation;
	int					tmp;
	int					sign;

	tmp = va_arg(*ap, int);
	sign = tmp;
	tmp_val = tmp < 0 ? -1 * (unsigned long long)tmp : (unsigned long long)tmp;
	size_allocation = ft_nblen_ull(tmp_val);
	size_allocation = ft_len_to_alloc(size_allocation, flag);
	output = ft_ulltoa_offset(tmp_val, size_allocation);
	output = ft_apply_precision_nb(output, flag, sign);
	output = ft_apply_padding_nb(output, flag, sign);
	return (output);
}
