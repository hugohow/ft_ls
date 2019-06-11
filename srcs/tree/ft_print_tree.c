/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 00:11:03 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/11 19:21:57 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_enqueue_node_tree(t_queue **p_queue, t_node_avlt *root)
{
	t_list *node;

	if (!(node = ft_memalloc(sizeof(t_list))))
		return (0);
	node->content = (void *)root;
	node->content_size = sizeof(root);
	node->next = NULL;
	if (p_queue == NULL || *p_queue == NULL)
		return (0);
	if (((*p_queue)->tail) == NULL)
	{
		(*p_queue)->tail = node;
		(*p_queue)->head = (*p_queue)->tail;
	}
	else
	{
		((*p_queue)->tail)->next = node;
		(*p_queue)->tail = node;
	}
	(*p_queue)->size = (*p_queue)->size + 1;
	return (1);
}

void		ft_print_tree_reverse(t_node_avlt *root, \
	t_queue **p_queue, int *p_index_g, t_content *content_root)
{
	t_content *content;

	if (root == NULL)
		return ;
	ft_print_tree_reverse(root->right, p_queue, p_index_g, content_root);
	content = (t_content *)(root->content);
	if (!(content->level == 0 && ft_can_browse_dir(content)))
	{
		*p_index_g = *p_index_g + 1;
		ft_print_content(root, *p_index_g, content_root);
	}
	if (content->level == 0 || content->flag & FLAG_CAP_R)
	{
		if (ft_can_browse_dir(content))
		{
			if (content->flag & FLAG_CAP_R && content->subtree == NULL)
				content->subtree = ft_browse_dir(content, NULL);
			ft_enqueue_node_tree(p_queue, root);
		}
	}
	ft_print_tree_reverse(root->left, p_queue, p_index_g, content_root);
}

void		ft_print_tree(t_node_avlt *root, t_queue **p_queue, \
	int *p_index_g, t_content *content_root)
{
	t_content *content;

	if (root == NULL)
		return ;
	ft_print_tree(root->left, p_queue, p_index_g, content_root);
	content = (t_content *)(root->content);
	if (!(content->level == 0 && ft_can_browse_dir(content)))
	{
		*p_index_g = *p_index_g + 1;
		ft_print_content(root, *p_index_g, content_root);
	}
	if (content->level == 0 || content->flag & FLAG_CAP_R)
	{
		if (ft_can_browse_dir(content))
		{
			if (content->flag & FLAG_CAP_R && content->subtree == NULL)
				content->subtree = ft_browse_dir(content, NULL);
			ft_enqueue_node_tree(p_queue, root);
		}
	}
	ft_print_tree(root->right, p_queue, p_index_g, content_root);
}
