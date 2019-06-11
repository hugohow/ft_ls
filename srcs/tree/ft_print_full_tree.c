/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_full_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 16:09:18 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/11 02:43:09 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_dequeue_node_tree(t_queue **p_queue)
{
	t_list *node;

	if (p_queue == NULL || *p_queue == NULL)
		return (0);
	if ((*p_queue)->head == NULL || (*p_queue)->size == 0)
		return (0);
	node = (*p_queue)->head;
	(*p_queue)->head = ((*p_queue)->head)->next;
	ft_memdel((void **)&node);
	if ((*p_queue)->size == 1)
		(*p_queue)->tail = (*p_queue)->head;
	(*p_queue)->size = (*p_queue)->size - 1;
	return (1);
}

void		ft_print_subtree(t_content *content, int *p_ret, int *p_index_g)
{
	DIR *p_dir;

	if (*p_index_g != 0)
		ft_printf("\n");
	*p_index_g = *p_index_g + 1;
	if (content->level != 0 || content->len != 1)
		ft_printf("%s:\n", content->path);
	if (content->flag & (FLAG_L | FLAG_O) && content->nb_files != 0)
		ft_printf("total %ld\n", content->total_size);
	if (content->st_mode == 0)
	{
		*p_ret = 1;
		if ((p_dir = opendir(content->path)) == NULL)
		{
			ft_putstr_fd("ls: ", 2);
			ft_putstr_fd(content->name, 2);
			ft_putstr_fd(": ", 2);
			perror("");
		}
	}
	else
		ft_print_full_tree(content->subtree, p_ret, p_index_g, content);
}

void		ft_print_full_tree(t_node_avlt *root, int *p_ret, int *p_index_g, t_content *content_dir)
{
	t_queue		*queue;
	t_content	*content_root;
	t_node_avlt	*node;

	if (root == NULL || root->content == NULL)
		return ;
	queue = ft_queue_init();
	content_root = (t_content *)(root->content);
	if (content_root->flag & FLAG_R)
		ft_print_tree_reverse(root, &queue, p_index_g, content_dir);
	else
		ft_print_tree(root, &queue, p_index_g, content_dir);
	while (queue->size)
	{
		node = (t_node_avlt *)((queue->head)->content);
		ft_print_subtree((t_content *)(node->content), p_ret, p_index_g);
		ft_dequeue_node_tree(&queue);
	}
	free(queue);
}
