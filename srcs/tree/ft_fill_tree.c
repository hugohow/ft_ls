/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:51:50 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 16:18:54 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_node_avlt	*ft_avlt_create_node(void *content, size_t content_size)
{
	t_node_avlt	*node;

	node = (t_node_avlt *)ft_memalloc(sizeof(t_node_avlt));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->content_size = content_size;
	node->height = 1;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

static t_node_avlt	*ft_avlt_add_node(t_node_avlt **p_root, void *content, \
	size_t content_size, int (*cmp)(t_node_avlt *, t_node_avlt *))
{
	t_node_avlt *node;

	node = ft_avlt_create_node(content, content_size);
	if (node == NULL)
		return (NULL);
	if (*p_root == NULL)
		*p_root = node;
	else
		node = ft_avlt_insert(p_root, node, cmp);
	if (node == NULL)
		return (NULL);
	return (node);
}

void				ft_fill_tree(t_node_avlt **root, t_content *ct, \
	t_node_avlt **root_err)
{
	if (ct->st_mode == 0 && root_err)
	{
		ft_avlt_add_node(root_err, (void *)ct, \
			sizeof(t_content), ft_nodecmp_path);
		return ;
	}
	if ((ct->flag & FLAG_CAP_S))
		ft_avlt_add_node(root, (void *)ct, sizeof(t_content), ft_nodecmp_size);
	else if ((ct->flag & FLAG_F))
		ft_avlt_add_node(root, (void *)ct, \
			sizeof(t_content), ft_nodecmp_unsorted);
	else if ((ct->flag & FLAG_T))
		ft_avlt_add_node(root, (void *)ct, sizeof(t_content), ft_nodecmp_date);
	else
		ft_avlt_add_node(root, (void *)ct, sizeof(t_content), ft_nodecmp_path);
}

void				ft_fill_tree_recursive(t_node_avlt **root, \
	t_content *content, t_node_avlt **root_err)
{
	if (ft_can_browse_dir(content))
		content->subtree = ft_browse_dir(content, root_err);
	ft_fill_tree(root, content, root_err);
}
