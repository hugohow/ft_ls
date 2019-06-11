/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_datum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 02:56:29 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/11 22:47:10 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_datum(t_content *content, t_content *r)
{
	struct stat		file_stat;
	struct passwd	*pwd;
	struct group	*grp;

	file_stat = content->file_stat;
	ft_printf(" %*d ", r->len_link, file_stat.st_nlink);
	if (~content->flag & FLAG_G)
	{
		if ((pwd = getpwuid(file_stat.st_uid)) != NULL)
			ft_printf("%-*s  ", r->len_owner, pwd->pw_name);
		else
			ft_printf("%-*d  ", r->len_uid, file_stat.st_uid);
	}
	if (~content->flag & FLAG_O)
	{
		if ((grp = getgrgid(file_stat.st_gid)) != NULL)
			ft_printf("%-*s", r->len_group, grp->gr_name);
		else
			ft_printf("%-*d", r->len_gid, file_stat.st_gid);
	}
	ft_putstr("  ");
	if (S_ISCHR(file_stat.st_mode) || S_ISBLK(file_stat.st_mode))
		ft_printf(" %*u, %*u ", r->len_major + 1, major(file_stat.st_rdev), \
			r->len_minor, minor(file_stat.st_rdev));
	else
		ft_printf("%*lld ", r->len_size, file_stat.st_size);
}
