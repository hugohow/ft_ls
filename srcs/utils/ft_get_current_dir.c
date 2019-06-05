/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_current_dir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:34:40 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 16:43:36 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_get_current_dir(const char *path, char *curr_dir)
{
	int i;

	ft_strcpy(curr_dir, path);
	i = 0;
	while (curr_dir[i])
		i++;
	if (i == 0)
		return (curr_dir);
	i--;
	while (curr_dir[i] == '/' && i >= 0)
		i--;
	while (curr_dir[i] != '/' && i >= 0)
		i--;
	if (curr_dir[i] == '/')
		curr_dir[i + 1] = 0;
	else
		curr_dir[0] = 0;
	return (curr_dir);
}
