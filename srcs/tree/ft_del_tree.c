/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 16:06:30 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 16:23:14 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	free_node(t_node_avlt *node)
{
	t_content *content;

	if (node)
	{
		content = (t_content *)(node->content);
		ft_del_tree((t_node_avlt **)&((content)->subtree));
		ft_memdel((void **)(&(content->path)));
		ft_memdel((void **)(&(content->name)));
		ft_memdel((void **)(&(content->error)));
		ft_memdel((void **)(&(content->link)));
		ft_memdel((void **)(&content));
		node->content_size = 0;
		ft_memdel((void **)(&node));
	}
}

void		ft_del_tree(t_node_avlt **p_root)
{
	if (p_root == NULL || *p_root == NULL)
		return ;
	ft_avlt_apply_postorder(*p_root, &free_node);
}
