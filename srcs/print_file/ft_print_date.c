/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_date.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 02:43:56 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/06 10:27:36 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_date(t_content *content)
{
	char	*string;
	time_t	now;

	now = time(NULL);
	string = ctime(&(content->time));
	ft_printf("%3.3s ", string + 4);
	ft_printf("%2.2s ", string + 8);
	if ((now - content->time) > SIXMONTHS || now < content->time)
		ft_printf("%5.4s ", string + 20);
	else
		ft_printf("%5.5s ", string + 11);
}
