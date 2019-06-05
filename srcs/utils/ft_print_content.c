/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 11:19:02 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 16:43:22 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_file_info(t_content *content, int index)
{
	if (content->flag & FLAG_L)
		ft_print_file_stat_long(content);
	else
		ft_print_file_stat(content, index);
}

void		ft_print_content(t_node_avlt *node, int index)
{
	t_content *content;

	content = (t_content *)(node->content);
	if (node == NULL || node->content == NULL)
		return ;
	ft_print_file_info(content, index);
}
