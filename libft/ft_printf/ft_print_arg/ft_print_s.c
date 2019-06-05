/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:24:51 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/05 15:05:06 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_print_s(va_list *ap, t_flag *flag)
{
	char	*output;
	char	*arg;
	size_t	size_allocation;

	arg = va_arg(*ap, char*);
	size_allocation = arg == NULL ? ft_strlen("(null)") : ft_strlen(arg);
	size_allocation = ft_len_to_alloc(size_allocation, flag);
	if (!(output = (char *)ft_memalloc(sizeof(char) * size_allocation)))
		return (NULL);
	output = ft_strcpy(output, arg == NULL ? "(null)" : arg);
	output = ft_apply_precision_str(output, flag, 1);
	output = ft_apply_padding_str(output, flag, 1);
	return (output);
}
