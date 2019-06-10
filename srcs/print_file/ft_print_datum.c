/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_datum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 02:56:29 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/10 22:58:35 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_datum(t_content *content, t_content *r)
{
	struct stat		file_stat;

	file_stat = content->file_stat;
	ft_printf(" %*d ", r->len_link, file_stat.st_nlink);
	if ((content->flag & FLAG_G) == 0)
	{
		if (content->pw_name)
			ft_printf("%-*s  ", r->len_owner, content->pw_name);
		else
			ft_printf("%-*d  ", r->len_uid, file_stat.st_uid);
	}
	if ((content->flag & FLAG_O) == 0)
	{
		if (content->gr_name)
			ft_printf("%-*s ", r->len_group, content->gr_name);
		else
			ft_printf("%-*d ", r->len_gid, file_stat.st_gid);
	}
	if (S_ISCHR(file_stat.st_mode) || S_ISBLK(file_stat.st_mode))
		ft_printf("%*u,  %*u ", r->len_major, major(file_stat.st_rdev), \
			r->len_minor, minor(file_stat.st_rdev));
	else
		ft_printf(" %*lld ", r->len_size, file_stat.st_size);
}
