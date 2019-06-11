/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_browse_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:33:40 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/11 18:11:25 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

	if (ft_nblen(file_stat.st_uid) > content->len_uid)
		content->len_uid = ft_nblen(file_stat.st_uid);

	if (ft_nblen(file_stat.st_gid) > content->len_gid)
		content->len_gid = ft_nblen(file_stat.st_gid);

	if (S_ISCHR(file_stat.st_mode) || S_ISBLK(file_stat.st_mode))
	{
		if (ft_nblen(major(file_stat.st_rdev)) > content->len_major)
			content->len_major = ft_nblen(major(file_stat.st_rdev));
		if (ft_nblen(minor(file_stat.st_rdev)) > content->len_minor)
			content->len_minor = ft_nblen(minor(file_stat.st_rdev));
	}
}

static void	fill_with_file(char *d_name, t_content *content, \
	t_node_avlt **root, t_node_avlt **root_err)
{
	char			*buff;
	t_content		*content_child;

	if (!(buff = (char *)ft_memalloc(sizeof(char) * (ft_strlen(content->path) + 5 + ft_strlen(d_name)))))
		return ;
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
	ft_memdel((void **)&buff);
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
