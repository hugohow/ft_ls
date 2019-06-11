/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file_stat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:20:38 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/11 20:22:59 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_file_stat(t_content *content, int index)
{
	struct stat file_stat;
	char		*tmp;

	(void)index;
	file_stat = content->file_stat;
	if (content->flag & FLAG_I)
		ft_printf("%ld ", file_stat.st_ino);
	if (content->level == 0)
	{
		ft_putstr_fd(content->path, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (content->flag & FLAG_CAP_G)
	{
		tmp = ft_get_file_name(content);
		ft_putstr_fd(tmp, 1);
		ft_putstr_fd("\n", 1);
		ft_memdel((void **)&tmp);
	}
	else
	{
		ft_putstr_fd(content->name, 1);
		ft_putstr_fd("\n", 1);
	}
}
