/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_padding_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:49:41 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/06 13:30:23 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_add_sign(char *str, t_flag *flag, int sign)
{
	if (ft_can_apply_plus(flag, sign))
		str = ft_strcat_r("+", str);
	if (ft_can_apply_minus(flag, sign))
		str = ft_strcat_r("-", str);
	if (ft_can_apply_space(flag, sign))
		str = ft_strcat_r(" ", str);
	return (str);
}

static size_t		get_size_to_add(t_flag *flag, int sign)
{
	unsigned int	str_len;

	str_len = 0;
	if (ft_can_apply_plus(flag, sign))
		str_len++;
	if (ft_can_apply_minus(flag, sign))
		str_len++;
	if (ft_can_apply_space(flag, sign))
		str_len++;
	str_len += 2;
	return (str_len);
}

static char			*str_to_fill(char *str, t_flag *flag, int sign)
{
	char			*to_add;
	unsigned int	to_add_len;
	unsigned int	i;

	to_add_len = get_size_to_add(flag, sign);
	if (to_add_len + ft_strlen(str) >= flag->width)
		return (ft_strdup(""));
	if (!(to_add = (char *)ft_memalloc(sizeof(char) * (flag->width + 2))))
		return (NULL);
	i = 0;
	while (to_add_len + ft_strlen(str) + i < flag->width)
	{
		to_add[i] = ft_can_fill_with_zeros(flag, sign) ? '0' : ' ';
		i++;
	}
	to_add[i] = '\0';
	return (to_add);
}

char				*ft_apply_padding_p(char *str, t_flag *flag, int sign)
{
	char			*to_add;

	to_add = str_to_fill(str, flag, sign);
	if (ft_can_fill_with_zeros(flag, sign))
	{
		str = ft_str_join(to_add, str, flag);
		str = ft_str_join(PREFIX_0X, str, flag);
	}
	else
	{
		str = ft_add_sign(str, flag, sign);
		str = ft_str_join(PREFIX_0X, str, flag);
		if (flag->minus == 1)
			str = ft_str_join_r(str, to_add, flag);
		else
			str = ft_str_join(to_add, str, flag);
	}
	ft_memdel((void **)&to_add);
	return (str);
}
