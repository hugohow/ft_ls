/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flaglen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:39:58 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/05 21:58:20 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valid_par(char c)
{
	if (c == ' ' || c == '#' || c == '0' || c == '-' || c == '+' || c == '*' \
		|| c == '$' || c == '.')
		return (1);
	if (ft_isdigit(c) == 1)
		return (1);
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 'L' || c == 't')
		return (1);
	return (0);
}
static int	is_valid_conv(char c)
{
	if (c == '%')
		return (1);
	else if (c == 'c')
		return (1);
	else if (c == 'd' || c == 'i')
		return (1);
	else if (c == 'o' || c == 'x' || c == 'X' || c == 'u' || c == 'b')
		return (1);
	else if (c == 'p')
		return (1);
	else if (c == 's')
		return (1);
	else if (c == 'f')
		return (1);
	else if (c == 'e')
		return (1);
	return (0);
}

size_t		ft_flaglen(const char *str)
{
	size_t	i;

	i = 1;
	while (str[i] && is_valid_par(str[i]) == 1)
	{
		if (str[i] == '%')
			break ;
		i++;
	}
	if (str[i] && is_valid_conv(str[i]))
		return (i);
	return (-1);
}
