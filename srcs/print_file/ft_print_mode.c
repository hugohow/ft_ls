/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 02:44:50 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/07 16:33:32 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		ft_get_letter_mode(unsigned long st_mode)
{
	if (S_ISREG(st_mode))
		return ('-');
	if (S_ISDIR(st_mode))
		return ('d');
	if (S_ISCHR(st_mode))
		return ('c');
	if (S_ISBLK(st_mode))
		return ('b');
	if (S_ISFIFO(st_mode))
		return ('p');
	if (S_ISLNK(st_mode))
		return ('l');
	if (S_ISSOCK(st_mode))
		return ('s');
	return ('?');
}

static void	ft_print_owner_permission(struct stat file_stat)
{
	ft_putchar_fd((file_stat.st_mode & S_IRUSR) ? 'r' : '-', 1);
	ft_putchar_fd((file_stat.st_mode & S_IWUSR) ? 'w' : '-', 1);
	if (!(file_stat.st_mode & S_IXUSR) && (file_stat.st_mode & S_ISUID))
		ft_putchar_fd('S', 1);
	else if ((file_stat.st_mode & S_IXUSR) && (file_stat.st_mode & S_ISUID))
		ft_putchar_fd('s', 1);
	else if (file_stat.st_mode & S_IXUSR)
		ft_putchar_fd('x', 1);
	else
		ft_putchar_fd('-', 1);
}

static void	ft_print_group_permission(struct stat file_stat)
{
	ft_putchar_fd((file_stat.st_mode & S_IRGRP) ? 'r' : '-', 1);
	ft_putchar_fd((file_stat.st_mode & S_IWGRP) ? 'w' : '-', 1);
	if (!(file_stat.st_mode & S_IXGRP) && (file_stat.st_mode & S_ISGID))
		ft_putchar_fd('S', 1);
	else if ((file_stat.st_mode & S_IXGRP) && (file_stat.st_mode & S_ISGID))
		ft_putchar_fd('s', 1);
	else if (file_stat.st_mode & S_IXGRP)
		ft_putchar_fd('x', 1);
	else
		ft_putchar_fd('-', 1);
}

static void	ft_print_other_permission(struct stat file_stat)
{
	ft_putchar_fd((file_stat.st_mode & S_IROTH) ? 'r' : '-', 1);
	ft_putchar_fd((file_stat.st_mode & S_IWOTH) ? 'w' : '-', 1);
	if (!(file_stat.st_mode & S_IXUSR) && \
		!(file_stat.st_mode & S_IXGRP) && (file_stat.st_mode & S_ISVTX))
		ft_putchar_fd('T', 1);
	else if ((file_stat.st_mode & S_IXUSR) && \
		(file_stat.st_mode & S_IXGRP) && (file_stat.st_mode & S_ISVTX))
		ft_putchar_fd('t', 1);
	else if (file_stat.st_mode & S_IXOTH)
		ft_putchar_fd('x', 1);
	else
		ft_putchar_fd('-', 1);
}

void		ft_print_mode(t_content *content)
{
	struct stat file_stat;

	file_stat = content->file_stat;
	ft_putchar_fd(ft_get_letter_mode(file_stat.st_mode), 1);
	ft_print_owner_permission(file_stat);
	ft_print_group_permission(file_stat);
	ft_print_other_permission(file_stat);
}
