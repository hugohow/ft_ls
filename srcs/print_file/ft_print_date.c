/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_date.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 02:43:56 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/11 14:39:51 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_nblen(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static char	*ft_strtim_return(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	return (str + i);
}

void		ft_print_date(t_content *content)
{
	char	*string;
	time_t	now;

	now = time(NULL);
	string = ctime((time_t *)&(content->time));
	ft_printf("%3.3s ", string + 4);
	ft_printf("%2.2s ", string + 8);
	if ((now - content->time) > SIXMONTHS || (long long)now < content->time)
		ft_printf("%5.*s ", ft_nblen(ft_strtim_return(string + 20)), \
			ft_strtim_return(string + 20));
	else
		ft_printf("%5.5s ", string + 11);
}
