/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_datum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 02:56:29 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 16:14:16 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_datum(t_content *content)
{
	struct stat		file_stat;
	struct passwd	*pwd;
	struct group	*grp;

	file_stat = content->file_stat;
	ft_printf("%4d ", file_stat.st_nlink);
	if ((content->flag & FLAG_G) == 0)
	{
		if ((pwd = getpwuid(file_stat.st_uid)) != NULL)
			ft_printf("%-10s ", pwd->pw_name);
		else
			ft_printf("%-10d ", file_stat.st_uid);
	}
	if ((grp = getgrgid(file_stat.st_gid)) != NULL)
		ft_printf("%-6s", grp->gr_name);
	else
		ft_printf("%-6d", file_stat.st_gid);
	if (S_ISCHR(file_stat.st_mode) || S_ISBLK(file_stat.st_mode))
		ft_printf("%5u,  %5u ", major(file_stat.st_rdev), \
			minor(file_stat.st_rdev));
	else
		ft_printf("%5lld  ", file_stat.st_size);
}
