/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 13:17:12 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/07 12:03:06 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_null(char *output, t_flag *flag, int fd)
{
	char	c;
	int		i;

	i = 0;
	c = 0;
	while (i < flag->character_i)
	{
		ft_putchar_fd(output[i], fd);
		i++;
	}
	write(1, &c, fd);
	i++;
	while (output[i])
	{
		ft_putchar_fd(output[i], fd);
		i++;
	}
	return (i);
}
