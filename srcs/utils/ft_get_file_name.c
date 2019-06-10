/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:53:47 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/11 00:58:18 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_get_file_name(const char *path, struct stat file_stat, long flag)
{
	char	*file_name;
	char	*color;
	char	*buff;

	file_name = ft_strrchr(path, '/');
	if (!(buff = (char *)ft_memalloc(sizeof(char) * (ft_strlen(path) + 40))))
		return (NULL);
	if (flag & FLAG_CAP_G)
		color = ft_get_color_bg_fg(file_stat, buff);
	if (ft_strcmp("/", path) == 0 || file_name == NULL)
		ft_strcat(buff, path);
	else if (ft_strlen(file_name) > 1)
		ft_strcat(buff, file_name + 1);
	else
	{
		ft_strcat(buff, path);
		buff[ft_strlen(file_name) - 1] = '\0';
	}
	if (flag & FLAG_CAP_G)
		ft_strcat(buff, ANSI_COLOR_RESET);
	return (buff);
}
