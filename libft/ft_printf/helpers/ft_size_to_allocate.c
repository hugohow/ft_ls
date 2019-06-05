/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_to_allocate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:55:17 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 11:18:42 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	max(int a, int b, int c)
{
	int		result;

	result = a;
	if (b > result)
		result = b;
	if (c > result)
		result = c;
	return (result);
}

int			ft_len_to_alloc(size_t original_nblen, t_flag *flag)
{
	return (max((int)(original_nblen + 10), (int)(flag->width + 10), \
		(int)(flag->precision + 10)));
}
