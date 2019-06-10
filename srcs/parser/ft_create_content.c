/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 11:19:07 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/11 01:02:11 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_content	*ft_content_err(char *path)
{
	t_content	*content;
	char		*buff;

	if (!(content = (t_content *)ft_memalloc(sizeof(t_content))))
		return (NULL);
	content->st_mode = 0;
	if (ft_strlen(path) == 0)
	{
		ft_memdel((void **)&content);
		ft_putstr_fd("ls: fts_open: No such file or directory", 2);
		return (NULL);
	}
	if (!(buff = (char *)ft_memalloc(sizeof(char) * (ft_strlen(path) + 40))))
	{
		ft_memdel((void **)&content);
		return (NULL);
	}
	ft_strcat(buff, "ls: ");
	ft_strcat(buff, path);
	ft_strcat(buff, ": No such file or directory");
	content->name = ft_strdup("");
	content->error = ft_strdup(buff);
	content->path = ft_strdup(path);
	content->link = NULL;
	ft_memdel((void **)&buff);
	return (content);
}

static t_content	*check_if_link_dir(t_content *content)
{
	ssize_t		ret;
	char		buf[PATH_MAX];
	char		curr_dir[PATH_MAX];
	struct stat	file_stat;

	if ((ret = readlink(content->path, buf, sizeof(buf))) >= 0)
	{
		buf[ret] = '\0';
		curr_dir[0] = 0;
		ft_get_current_dir(content->path, curr_dir);
		ft_strcat(curr_dir, buf);
		if (stat(curr_dir, &file_stat) < 0)
			return (content);
		if (content->level == 0 && S_ISDIR(file_stat.st_mode) \
			&& (content->flag & FLAG_L) == 0)
		{
			content->st_mode = file_stat.st_mode;
			ft_memdel((void **)&(content->name));
			content->name = ft_get_file_name(buf, file_stat, content->flag);
			content->file_stat = file_stat;
			content->st_size = file_stat.st_size;
		}
		content->link = ft_strdup(buf);
	}
	return (content);
}

static t_content	*ft_get_default_values(t_content *content, long flag, \
	int level, size_t len)
{
	struct passwd	*pwd;
	struct group	*grp;
	
	content->nb_files = 0;
	content->level = level;
	content->len = len;
	content->total_size = 0;
	content->subtree = NULL;
	content->flag = flag;
	content->st_size = (content->file_stat).st_size;
	if (flag & FLAG_CAP_U)
	{
		content->time = (content->file_stat).st_birthtime;
		content->time_sec = (content->file_stat).st_birthtimespec.tv_sec;	
		content->time_nsec = (content->file_stat).st_mtimespec.tv_nsec;	
	}
	else if (flag & FLAG_U)
	{
		content->time = (content->file_stat).st_atime;
		content->time_sec = (content->file_stat).st_atimespec.tv_sec;
		content->time_nsec = (content->file_stat).st_mtimespec.tv_nsec;
	}
	else
	{
		content->time = (content->file_stat).st_mtime;
		content->time_sec = (content->file_stat).st_mtimespec.tv_sec;
		content->time_nsec = (content->file_stat).st_mtimespec.tv_nsec;
	}
	content->has_extended_attributes = has_extended_attributes(content->path);
	content->has_acl = has_acl(content->path);
	content->error = NULL;
	content->link = NULL;
	content->len_link = 0;
	content->len_owner = 0;
	content->len_group = 0;
	content->len_size = 0;
	content->len_uid = 0;
	content->len_gid = 0;
	content->len_major = 0;
	content->len_minor = 0;
	content->len_ino = 0;
	if ((content->flag & FLAG_G) == 0 && ((pwd = getpwuid((content->file_stat).st_uid)) != NULL))
		content->pw_name = pwd->pw_name;
	else
		content->pw_name = NULL;
	if ((content->flag & FLAG_O) == 0 && (grp = getgrgid((content->file_stat).st_gid)) != NULL)
		content->gr_name = grp->gr_name;
	else
		content->gr_name = NULL;


	return (content);
}

t_content			*ft_create_content(char *path, long flag, \
	int level, size_t len)
{
	t_content	*content;
	struct stat	file_stat;

	if (lstat(path, &file_stat) < 0)
		return (ft_content_err(path));
	if (!(content = (t_content *)ft_memalloc(sizeof(t_content))))
		return (NULL);
	content->file_stat = file_stat;
	content->st_mode = file_stat.st_mode;
	content->path = ft_strdup(path);
	content->name = ft_get_file_name(path, file_stat, flag);
	content = ft_get_default_values(content, flag, level, len);
	if (S_ISLNK(content->st_mode))
		content = check_if_link_dir(content);
	return (content);
}
