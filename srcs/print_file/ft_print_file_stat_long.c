/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file_stat_long.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:20:10 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 16:14:52 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_file_stat_long(t_content *content)
{
	struct stat file_stat;

	file_stat = content->file_stat;
	if (content->flag & FLAG_I)
		ft_printf("%ld ", file_stat.st_ino);
	ft_print_mode(content);
	ft_print_acl_attr(content);
	ft_print_datum(content);
	ft_print_date(content);
	ft_print_path(content);
	ft_putchar_fd('\n', 1);
}
