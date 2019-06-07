/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_offset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:07:35 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/06 13:30:08 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_ulltoa_offset(unsigned long long nb, size_t size_allocation)
{
	char	*output;
	size_t	nb_len;

	nb_len = ft_nblen_ull(nb);
	if (!(output = (char *)ft_memalloc(sizeof(char) * size_allocation)))
		return (NULL);
	output[0] = '0';
	output[nb_len] = '\0';
	while (nb != 0)
	{
		output[--nb_len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (output);
}
