/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen_ull.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:07:31 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/25 19:08:00 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_nblen_ull(unsigned long long nb)
{
	size_t	nblen;

	nblen = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		nblen++;
	}
	return (nblen);
}
