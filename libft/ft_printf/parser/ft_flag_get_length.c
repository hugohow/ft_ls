/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_get_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:27:34 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/31 12:25:16 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valid_conversion(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' \
		|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X'\
		|| c == 'c' || c == 'C' || c == 'f')
		return (1);
	return (0);
}

static int	is_valid_length(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 'L' || c == 't')
		return (1);
	return (0);
}

int			ft_flag_get_length(char *flag)
{
	size_t	i;

	i = 0;
	while (flag[i] && is_valid_conversion(flag[i]) == 0)
		i++;
	if (i-- > 1)
	{
		while (i > 0 && is_valid_length(flag[i]) == 0)
			i--;
		if (flag[i] == 'j')
			return (LENGTH_J);
		if (flag[i] == 'z')
			return (LENGTH_Z);
		if (flag[i] == 'h' && i > 1 && flag[i - 1] == 'h')
			return (LENGTH_HH);
		if (flag[i] == 'h')
			return (LENGTH_H);
		if (flag[i] == 'l' && i > 1 && flag[i - 1] == 'l')
			return (LENGTH_LL);
		if (flag[i] == 'l')
			return (LENGTH_L);
		if (flag[i] == 'L')
			return (LENGTH_L_MAJ);
	}
	return (0);
}
