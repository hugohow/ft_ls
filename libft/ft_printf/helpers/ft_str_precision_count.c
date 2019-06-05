/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_precision_count.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:13:21 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/25 14:27:28 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_precision_count(char *str, int offset)
{
	int count;
	int i;

	i = offset;
	count = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || ft_isalpha(str[i]))
		{
			while (str[i] && (ft_isdigit(str[i]) || ft_isalpha(str[i])))
			{
				count++;
				i++;
			}
			if (str[i] == '\0')
				break ;
		}
		i++;
	}
	return (count);
}
