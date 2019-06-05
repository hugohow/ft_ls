/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_date.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 02:43:56 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 16:12:45 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_date(t_content *content)
{
	time_t	now;

	now = time(NULL);
	ft_printf("%.6s ", ctime(&(content->time)) + 4);
	if ((now - content->time) > SIXMONTHS || now < content->time)
		ft_printf("%.5s  ", ctime(&(content->time)) + 19);
	else
		ft_printf("%.5s  ", ctime(&(content->time)) + 11);
}
