/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:26:58 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 17:48:09 by hhow-cho         ###   ########.fr       */
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

//        a     black
//        b     red
//        c     green
//        d     brown
//        e     blue
//        f     magenta
//        g     cyan
//        h     light grey
//        A     bold black, usually shows up as dark grey
//        B     bold red
//        C     bold green
//        D     bold brown, usually shows up as yellow
//        E     bold blue
//        F     bold magenta
//        G     bold cyan
//        H     bold light grey; looks like bright white
//        x     default foreground or background



//        a     black
//        b     red
//        c     green
//        d     brown
//        e     blue
//        f     magenta
//        g     cyan
//        h     light grey
//        A     bold black, usually shows up as dark grey
//        B     bold red
//        C     bold green
//        D     bold brown, usually shows up as yellow
//        E     bold blue
//        F     bold magenta
//        G     bold cyan
//        H     bold light grey; looks like bright white
//        x     default foreground or background

//  Note that the above are standard ANSI colors.  The actual display may differ depending on the
//  color capabilities of the terminal in use.

//  The order of the attributes are as follows:

//        1.   directory
//        2.   symbolic link
//        3.   socket
//        4.   pipe
//        5.   executable
//        6.   block special
//        7.   character special



//        8.   executable with setuid bit set
//        9.   executable with setgid bit set
//        10.  directory writable to others, with sticky bit
//        11.  directory writable to others, without sticky bit

char	*ft_get_color_bg_fg(struct stat file_stat, char *buff)
{
	char *colors;
	int i;
	char fg[10];
	char bg[10];
	int k;
	colors = getenv("LSCOLORS");
	if (colors == NULL)
		return (buff);

//        10.  directory writable to others, with sticky bit
	if (S_ISDIR(file_stat.st_mode) && file_stat.st_mode & S_ISTXT)
		i = 18;
	else if (S_ISDIR(file_stat.st_mode) && (file_stat.st_mode & S_ISTXT) == 0)
		i = 20;
	else if (S_ISDIR(file_stat.st_mode))
		i = 0;
	else if (S_ISLNK(file_stat.st_mode))
		i = 2;
	else if (S_ISSOCK(file_stat.st_mode))
		i = 4;
	else if (S_ISFIFO(file_stat.st_mode))
		i = 6;
	else if (file_stat.st_mode & S_IXUSR)
		i = 8;
	else if (S_ISBLK(file_stat.st_mode))
		i = 10;
	else if (S_ISCHR(file_stat.st_mode))
		i = 12;
	else if (file_stat.st_mode & S_ISUID)
		i = 14;
//        9.   executable with setgid bit set
	else if (file_stat.st_mode & S_ISGID)
		i = 16;
	else
		return (NULL);
	k = 0;
	fg[0] = 0;
	while (g_tab_colors_fg[k].key)
	{
		if (g_tab_colors_fg[k].key == colors[i])
		{
			ft_strcpy(fg, g_tab_colors_fg[k].str);
			break;
		}
		k++;
	}
	k = 0;
	bg[0] = 0;
	while (g_tab_colors_bg[k].key)
	{
		if (g_tab_colors_bg[k].key == colors[i + 1])
		{
			ft_strcpy(bg, g_tab_colors_bg[k].str);
			break;
		}
		k++;
	}
	ft_strcat(buff, fg);
	ft_strcat(buff, bg);
	return (buff);
}
