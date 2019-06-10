/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_browse_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:33:40 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/10 23:01:32 by hhow-cho         ###   ########.fr       */
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

static int	ft_nblen(int nb)
{
	int		nblen;

	nblen = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		nblen++;
	}
	while (nb != 0)
	{
		nb /= 10;
		nblen++;
	}
	return (nblen);
}

static int	ft_strlen_m(const char *str)
{
	int length;

	length = 0;
	if (str == NULL)
		return (0);
	while (str[length])
		length++;
	return (length);
}


static void	update_len(t_content *content, t_content *content_child)
{
	struct stat file_stat;

	file_stat = content_child->file_stat;
	if (ft_nblen(file_stat.st_nlink) > content->len_link)
		content->len_link = ft_nblen(file_stat.st_nlink);
	if (ft_strlen_m(content_child->pw_name) > content->len_owner)
		content->len_owner = ft_strlen_m(content_child->pw_name);
	if (ft_strlen_m(content_child->gr_name) > content->len_group)
		content->len_group = ft_strlen_m(content_child->gr_name);

	if (ft_nblen(content_child->st_size) > content->len_size)
		content->len_size = ft_nblen(content_child->st_size);

	if (ft_nblen(file_stat.st_ino) > content->len_ino)
		content->len_ino = ft_nblen(file_stat.st_ino);
	content->len_uid = 10;
	content->len_gid = 10;
	content->len_major = 10;
	content->len_minor = 10;
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
			update_len(content, content_child);
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
