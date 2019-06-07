/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:26:58 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/07 16:47:30 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static const t_color	g_tab_colors_fg[] =
{
	{'a', ANSI_COLOR_FG_BLACK},
	{'b', ANSI_COLOR_FG_RED},
	{'c', ANSI_COLOR_FG_GREEN},
	{'d', ANSI_COLOR_FG_BROWN},
	{'e', ANSI_COLOR_FG_BLUE},
	{'f', ANSI_COLOR_FG_MAGENTA},
	{'g', ANSI_COLOR_FG_CYAN},
	{'h', ANSI_COLOR_FG_WITHE},
	{'A', ANSI_COLOR_FG_BOLD_BLACK},
	{'B', ANSI_COLOR_FG_BOLD_RED},
	{'C', ANSI_COLOR_FG_BOLD_GREEN},
	{'D', ANSI_COLOR_FG_BOLD_BROWN},
	{'E', ANSI_COLOR_FG_BOLD_BLUE},
	{'F', ANSI_COLOR_FG_BOLD_MAGENTA},
	{'G', ANSI_COLOR_FG_BOLD_CYAN},
	{'H', ANSI_COLOR_FG_BOLD_GREY},
	{'x', ""},
	{0, ""},
};

static const t_color	g_tab_colors_bg[] =
{
	{'a', ANSI_COLOR_BG_BLACK},
	{'b', ANSI_COLOR_BG_RED},
	{'c', ANSI_COLOR_BG_GREEN},
	{'d', ANSI_COLOR_BG_BROWN},
	{'e', ANSI_COLOR_BG_BLUE},
	{'f', ANSI_COLOR_BG_MAGENTA},
	{'g', ANSI_COLOR_BG_CYAN},
	{'h', ANSI_COLOR_BG_WITHE},
	{'A', ANSI_COLOR_BG_BOLD_BLACK},
	{'B', ANSI_COLOR_BG_BOLD_RED},
	{'C', ANSI_COLOR_BG_BOLD_GREEN},
	{'D', ANSI_COLOR_BG_BOLD_BROWN},
	{'E', ANSI_COLOR_BG_BOLD_BLUE},
	{'F', ANSI_COLOR_BG_BOLD_MAGENTA},
	{'G', ANSI_COLOR_BG_BOLD_CYAN},
	{'H', ANSI_COLOR_BG_BOLD_GREY},
	{'x', ""},
	{0, ""},
};

static int				get_index(struct stat file_stat)
{
	if (S_ISLNK(file_stat.st_mode))
		return (2);
	else if (S_ISSOCK(file_stat.st_mode))
		return (4);
	else if (S_ISFIFO(file_stat.st_mode))
		return (6);
	else if (S_ISBLK(file_stat.st_mode))
		return (10);
	else if (S_ISCHR(file_stat.st_mode))
		return (12);
	else if (S_ISDIR(file_stat.st_mode) && (file_stat.st_mode & S_IWOTH)\
		&& (file_stat.st_mode & S_ISVTX))
		return (18);
	else if (S_ISDIR(file_stat.st_mode) && (file_stat.st_mode & S_IWOTH))
		return (20);
	else if (S_ISDIR(file_stat.st_mode))
		return (0);
	else if ((file_stat.st_mode & S_IXUSR) && (file_stat.st_mode & S_ISUID))
		return (14);
	else if ((file_stat.st_mode & S_IXUSR) && (file_stat.st_mode & S_ISGID))
		return (16);
	else if (file_stat.st_mode & S_IXUSR)
		return (8);
	else
		return (-1);
}

static char				*get_fg(char color, char *fg)
{
	int		k;

	k = 0;
	fg[0] = 0;
	while (g_tab_colors_fg[k].key)
	{
		if (g_tab_colors_fg[k].key == color)
		{
			ft_strcpy(fg, g_tab_colors_fg[k].str);
			break ;
		}
		k++;
	}
	return (fg);
}

static char				*get_bg(char color, char *bg)
{
	int	k;

	k = 0;
	bg[0] = 0;
	while (g_tab_colors_bg[k].key)
	{
		if (g_tab_colors_bg[k].key == color)
		{
			ft_strcpy(bg, g_tab_colors_bg[k].str);
			break ;
		}
		k++;
	}
	return (bg);
}

char					*ft_get_color_bg_fg(struct stat file_stat, char *buff)
{
	char	*colors;
	int		i;
	char	fg[10];
	char	bg[10];

	colors = getenv("LSCOLORS");
	if (colors == NULL)
		return (buff);
	i = get_index(file_stat);
	if (ft_strlen(colors) != 22)
		return (buff);
	if (i == -1)
		return (buff);
	get_fg(colors[i], fg);
	get_bg(colors[i + 1], bg);
	ft_strcat(buff, fg);
	ft_strcat(buff, bg);
	return (buff);
}
