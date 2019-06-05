/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_get_minus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:37:28 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/05 22:45:46 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_flag_get_minus(char *flag)
{
	unsigned int	i;

	i = 0;
	while (flag[i])
	{
		if (flag[i] == '-')
			return (1);
		i++;
	}
	return (0);
}
