/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f_l_maj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 12:34:26 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/07 12:20:07 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_bin_floating_point(long double nb)
{
	char			*output;
	int				i;
	unsigned char	t[10 + 1];
	char			tmp[10];

	if (!(output = (char *)ft_memalloc(sizeof(*output) * 100)))
		return (NULL);
	ft_memcpy(t, &nb, 10);
	i = (10) - 1;
	while (i != -1)
	{
		output = ft_strcat(output, ft_get_binary(t[i], tmp));
		i--;
	}
	return (output);
}

static size_t	ft_nblen(long double nb)
{
	size_t		nblen;

	nblen = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		nblen++;
	}
	while (nb != 0)
	{
		if (nblen == 4933)
			break ;
		nb /= 10;
		nblen++;
	}
	return (nblen);
}

char			*ft_print_f_l_maj(va_list *ap, t_flag *flag)
{
	char		*output;
	long double	tmp;
	size_t		size_allocation;
	int			sign;
	char		*to_free;

	tmp = (long double)va_arg(*ap, long double);
	size_allocation = flag->precision < 40 ? 40 : flag->precision + 5;
	size_allocation += ft_nblen(tmp);
	to_free = get_bin_floating_point(tmp);
	sign = to_free[0] == '1' ? -1 : 1;
	output = ft_fltoa(tmp, to_free, flag, size_allocation);
	if (flag->precision == -1)
		output = ft_bigint_round(output, 6, size_allocation);
	else
		output = ft_bigint_round(output, flag->precision, size_allocation);
	output = ft_apply_padding_nb(output, flag, sign);
	if (flag->hash && flag->precision == 0)
		output = ft_str_join_r(output, ".", flag);
	ft_memdel((void **)&to_free);
	return (output);
}
