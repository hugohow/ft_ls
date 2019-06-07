/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_left_shift.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 20:29:25 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/29 14:32:29 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** "abc" << = "bc "
*/

char	*ft_str_left_shift(char *str, int index_until)
{
	int j;

	j = 0;
	if (index_until < 0)
	{
		return (str);
	}
	if (index_until == 0)
	{
		str[0] = ' ';
		return (str);
	}
	if (index_until == 1)
	{
		str[0] = str[1];
		str[1] = ' ';
		return (str);
	}
	while (j < index_until - 1)
	{
		str[j] = str[j + 1];
		j++;
	}
	str[j] = ' ';
	return (str);
}
