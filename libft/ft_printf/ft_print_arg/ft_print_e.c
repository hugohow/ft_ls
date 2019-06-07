/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 12:34:10 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/07 16:15:23 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_bin_floating_point(double nb)
{
	char			*output;
	int				i;
	unsigned char	t[sizeof(double) + 1];
	char			tmp[10];

	if (!(output = (char *)ft_memalloc(sizeof(char) * 100)))
		return (NULL);
	ft_memcpy(t, &nb, sizeof(double));
	i = (sizeof(double)) - 1;
	while (i != -1)
	{
		output = ft_strcat(output, ft_get_binary(t[i], tmp));
		i--;
	}
	return (output);
}

static char		*ft_print_e_particular(char *output, t_flag *flag)
{
	if (output[0] == '.')
		output = ft_str_join("0", output, flag);
	if (ft_strlen(output) == 0)
		output = ft_strcpy(output, "0");
	if (flag->hash && flag->precision == 0)
		output = ft_str_join_r(output, ".", flag);
	return (output);
}

static char		*ft_round_e(char *out, double tmp, t_flag *flag, size_t size)
{
	int	expo;

	expo = ft_apply_e(out);
	if (tmp == 0)
		expo = 0;
	tmp = flag->precision == -1 ? 6 : flag->precision;
	out = ft_bigint_round(out, 6, size);
	out = ft_print_e_particular(out, flag);
	return (out);
}

static size_t	ft_nblen(double nb)
{
	size_t	nblen;

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
		if (nblen == 300)
			break ;
		nb /= 10;
		nblen++;
	}
	return (nblen);
}

char			*ft_print_e(va_list *ap, t_flag *flag)
{
	char	*output;
	double	tmp;
	int		sign;
	char	*to_free;
	size_t	size_allocation;

	tmp = (double)va_arg(*ap, double);
	size_allocation = flag->precision < 40 ? 40 : flag->precision + 5;
	size_allocation += ft_nblen(tmp);
	to_free = get_bin_floating_point(tmp);
	sign = to_free[0] == '1' ? -1 : 1;
	output = ft_ftoa(tmp, to_free, flag, size_allocation);
	if (ft_strchr(output, 'i') == 0 && ft_strchr(output, 'n') == 0)
	{
		output = ft_round_e(output, tmp, flag, size_allocation);
		output = ft_apply_padding_e(output, flag, sign, expo);
	}
	else
		output = ft_apply_padding_nb(output, flag, sign);
	ft_memdel((void **)&to_free);
	return (output);
}
