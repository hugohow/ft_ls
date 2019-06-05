/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_full_tree_err.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 16:09:18 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 16:23:03 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_content_err(t_node_avlt *node)
{
	t_content *content;

	if (node == NULL || node->content == NULL)
		return ;
	content = (t_content *)(node->content);
	ft_putstr_fd(content->error, 2);
	ft_putstr_fd("\n", 2);
}

void		ft_print_full_tree_err(t_node_avlt *root)
{
	ft_avlt_apply_inorder(root, &ft_print_content_err);
}
