/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 02:57:03 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 16:15:10 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_path(t_content *content)
{
	struct stat	file_stat;
	ssize_t		ret;
	char		buf[BUFF_SIZE];

	file_stat = content->file_stat;
	if (content->level == 0)
		ft_printf("%s", content->path);
	else
		ft_printf("%s", content->name);
	if (S_ISLNK(file_stat.st_mode))
	{
		if ((ret = readlink(content->path, buf, sizeof(buf))) >= 0)
		{
			buf[ret] = '\0';
			ft_printf(" -> %s", buf);
		}
	}
}
