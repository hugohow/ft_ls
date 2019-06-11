/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 11:19:02 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/11 14:48:34 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_file_info(t_content *content, int index, t_content *ct_r)
{
	if (content->flag & (FLAG_L | FLAG_O))
		ft_print_file_stat_long(content, ct_r);
	else
		ft_print_file_stat(content, index);
}

void		ft_print_content(t_node_avlt *node, int index, t_content *ct_r)
{
	t_content *content;

	content = (t_content *)(node->content);
	if (node == NULL || node->content == NULL)
		return ;
	ft_print_file_info(content, index, ct_r);
}
