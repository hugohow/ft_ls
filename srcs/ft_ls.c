/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:45:10 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 15:53:38 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t		ft_str_lst_len(char **lst)
{
	size_t len;

	len = 0;
	while (lst[len])
		len++;
	return (len);
}

static int	fill_tree(t_node_avlt **root_tree_content, \
t_node_avlt **root_tree_err, char **argv, long flag)
{
	char		**content_lst;
	t_content	*content;
	int			len;

	content_lst = argv;
	if (ft_str_lst_len(argv) == 0)
	{
		content = ft_create_content(".", flag, 0, 1);
		if (content == NULL)
			return (1);
		ft_fill_tree_recursive(root_tree_content, content, root_tree_err);
		return (0);
	}
	len = ft_str_lst_len(content_lst);
	while (*content_lst)
	{
		content = ft_create_content(*content_lst, flag, 0, len);
		if (content == NULL)
			return (1);
		ft_fill_tree_recursive(root_tree_content, content, root_tree_err);
		content_lst++;
	}
	return (0);
}

static int	print_trees(t_node_avlt **root_tree_content, \
t_node_avlt **root_tree_err)
{
	int	ret;
	int	index_g;

	index_g = 0;
	ret = 0;
	if (*root_tree_err)
	{
		ft_print_full_tree_err(*root_tree_err);
		ft_print_full_tree(*root_tree_content, &ret, &index_g);
		return (1);
	}
	ret = 0;
	ft_print_full_tree(*root_tree_content, &ret, &index_g);
	return (ret);
}

static void	free_trees(t_node_avlt **root_tree_content, \
t_node_avlt **root_tree_err)
{
	ft_del_tree(root_tree_content);
	ft_del_tree(root_tree_err);
	free(root_tree_content);
	free(root_tree_err);
}

int			main(int argc, char **argv)
{
	long		flag;
	t_node_avlt	**root_tree_content;
	t_node_avlt	**root_tree_err;
	int			ret;

	(void)argc;
	argv++;
	flag = ft_parse_input(&argv);
	if (flag == -1)
		return (1);
	root_tree_content = (t_node_avlt **)ft_memalloc(sizeof(t_node_avlt *));
	root_tree_err = (t_node_avlt **)ft_memalloc(sizeof(t_node_avlt *));
	if (root_tree_err == NULL || root_tree_content == NULL)
		return (1);
	if (fill_tree(root_tree_content, root_tree_err, argv, flag) == 1)
	{
		free_trees(root_tree_content, root_tree_err);
		return (1);
	}
	ret = print_trees(root_tree_content, root_tree_err);
	free_trees(root_tree_content, root_tree_err);
	return (ret);
}
