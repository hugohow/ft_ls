/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_browse_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:33:40 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 16:42:42 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_can_browse_dir(t_content *content)
{
	if (content->level != 0 && (ft_strcmp(content->name, ".") == 0 || \
		ft_strcmp(content->name, "..") == 0))
		return (0);
	return ((content->flag & FLAG_D) == 0 && S_ISDIR(content->st_mode));
}

static int	file_is_hidden(char *name)
{
	if (ft_strcmp(name, ".") == 0
		|| ft_strcmp(name, "..") == 0 || name[0] == '.')
		return (1);
	return (0);
}

static void	fill_with_file(char *d_name, t_content *content, \
	t_node_avlt **root, t_node_avlt **root_err)
{
	char			buff[BUFF_SIZE];
	t_content		*content_child;

	buff[0] = 0;
	ft_strcat(buff, content->path);
	ft_strcat(buff, "/");
	ft_strcat(buff, d_name);
	if (file_is_hidden(d_name) == 0 || \
		(file_is_hidden(d_name) && content->flag & FLAG_A))
	{
		content_child = ft_create_content(buff, \
			content->flag, content->level + 1, 0);
		if (content_child)
		{
			ft_fill_tree(root, content_child, root_err);
			content->nb_files = content->nb_files + 1;
			content->total_size = content->total_size + \
				(content_child->file_stat).st_blocks;
		}
	}
}

t_node_avlt	*ft_browse_dir(t_content *content, t_node_avlt **root_err)
{
	t_node_avlt		*root;
	DIR				*p_dir;
	struct dirent	*p_dirent;

	root = NULL;
	if ((p_dir = opendir(content->path)) == NULL)
	{
		content->st_mode = 0;
		return (NULL);
	}
	while ((p_dirent = readdir(p_dir)) != NULL)
		fill_with_file(p_dirent->d_name, content, &root, root_err);
	closedir(p_dir);
	return (root);
}
