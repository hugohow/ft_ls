/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodecmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:32:25 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/13 12:23:35 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_nodecmp_date(t_node_avlt *node1, t_node_avlt *node2)
{
	long long	ret;
	t_content	*file1;
	t_content	*file2;

	file1 = ((t_content *)(node1->content));
	file2 = ((t_content *)(node2->content));
	ret = file2->sec - file1->sec;
	if (ret != 0)
		return (ret > 0 ? 1 : -1);
#ifdef __APPLE__
	ret = file2->nsec - file1->nsec;
	if (ret != 0)
		return (ret > 0 ? 1 : -1);
#endif
	return (ft_nodecmp_path(node1, node2));
}

int	ft_nodecmp_path(t_node_avlt *node1, t_node_avlt *node2)
{
	t_content	*file1;
	t_content	*file2;

	file1 = ((t_content *)(node1->content));
	file2 = ((t_content *)(node2->content));
	return (ft_strcmp(file1->path, file2->path));
}

int	ft_nodecmp_unsorted(t_node_avlt *node1, t_node_avlt *node2)
{
	(void)node1;
	(void)node2;
	return (-1);
}

int	ft_nodecmp_size(t_node_avlt *node1, t_node_avlt *node2)
{
	t_content	*file1;
	t_content	*file2;
	long long	ret;

	file1 = ((t_content *)(node1->content));
	file2 = ((t_content *)(node2->content));
	ret = (file2->st_size - file1->st_size);
	if (ret < 0)
		return (-1);
	if (ret > 0)
		return (1);
	return (ft_nodecmp_path(node1, node2));
}
