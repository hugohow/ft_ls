/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_default_values.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 01:13:41 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/11 22:23:51 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	get_null_values(t_content *content)
{
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
	content->total_size = 0;
	content->subtree = NULL;
	content->nb_files = 0;
}

static void	get_time(t_content *content, long flag)
{
	if (flag & FLAG_CAP_U)
	{
		content->time = (time_t)(content->file_stat).st_birthtime;
		content->sec = (long)(content->file_stat).st_birthtimespec.tv_sec;
		content->nsec = (long)(content->file_stat).st_mtimespec.tv_nsec;
	}
	else if (flag & FLAG_U)
	{
		content->time = (time_t)(content->file_stat).st_atime;
		content->sec = (long)(content->file_stat).st_atimespec.tv_sec;
		content->nsec = (long)(content->file_stat).st_mtimespec.tv_nsec;
	}
	else
	{
		content->time = (time_t)(content->file_stat).st_mtime;
		content->sec = (long)(content->file_stat).st_mtimespec.tv_sec;
		content->nsec = (long)(content->file_stat).st_mtimespec.tv_nsec;
	}
}

t_content	*ft_get_default_values(t_content *content, long flag, \
	int level, size_t len)
{
	struct passwd	*pwd;
	struct group	*grp;

	content->level = level;
	content->len = len;
	content->flag = flag;
	content->st_size = (content->file_stat).st_size;
	content->has_extended_attributes = has_extended_attributes(content->path);
	content->has_acl = has_acl(content->path);
	get_time(content, flag);
	get_null_values(content);
	if (((pwd = getpwuid((content->file_stat).st_uid)) != NULL))
		content->pw_name = pwd->pw_name;
	else
		content->pw_name = NULL;
	if ((grp = getgrgid((content->file_stat).st_gid)) != NULL)
		content->gr_name = grp->gr_name;
	else
		content->gr_name = NULL;
	return (content);
}
