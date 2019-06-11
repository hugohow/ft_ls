/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 18:11:19 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/11 19:21:31 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_can_browse_dir(t_content *content)
{
	if (content->level != 0 && \
		(ft_strcmp(ft_get_file_name_raw(content), ".") == 0 || \
		ft_strcmp(ft_get_file_name_raw(content), "..") == 0))
		return (0);
	return ((content->flag & FLAG_D) == 0 && S_ISDIR(content->st_mode));
}

int	file_is_hidden(char *name)
{
	if (ft_strcmp(name, ".") == 0
		|| ft_strcmp(name, "..") == 0 || name[0] == '.')
		return (1);
	return (0);
}
