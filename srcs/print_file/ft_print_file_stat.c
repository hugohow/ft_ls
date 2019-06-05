/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file_stat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:20:38 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 16:11:37 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_file_stat(t_content *content, int index)
{
	struct stat file_stat;

	(void)index;
	file_stat = content->file_stat;
	if (content->flag & FLAG_I)
		ft_printf("%ld ", file_stat.st_ino);
	ft_printf("%s\n", content->name);
}
