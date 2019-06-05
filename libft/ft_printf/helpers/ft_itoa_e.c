/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:37:21 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/05 18:38:07 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_nblen(long nb)
{
	size_t		nblen;

	nblen = 0;
	if (nb == 0)
		return (2);
	while (nb != 0)
	{
		nb /= 10;
		nblen++;
	}
	nblen++;
	return (nblen);
}

char			*ft_itoa_e(int nb)
{
	char		*output;
	size_t		nb_len;
	long		n;

	n = nb;
	nb_len = ft_nblen(n) + 1;
	if (!(output = (char *)ft_memalloc((nb_len + 4) * sizeof(char))))
		return (NULL);
	output[0] = 'e';
	output[1] = n < 0 ? '-' : '+';
	n = n < 0 ? -n : n;
	if (n < 10)
	{
		output[nb_len - 1] = '0';
		output[nb_len] = n + '0';
		output[nb_len + 1] = '\0';
		return (output);
	}
	output[nb_len] = '\0';
	while (n != 0)
	{
		output[--nb_len] = (n % 10) + '0';
		n /= 10;
	}
	return (output);
}
