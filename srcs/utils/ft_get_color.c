/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:26:58 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/06 23:16:35 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// static char get_other_x(struct stat file_stat)
// {
// 	if (!(file_stat.st_mode & S_IXUSR) && \
// 		!(file_stat.st_mode & S_IXGRP) && (file_stat.st_mode & S_ISVTX))
// 		return('T');
// 	else if ((file_stat.st_mode & S_IXUSR) && \
// 		(file_stat.st_mode & S_IXGRP) && (file_stat.st_mode & S_ISVTX))
// 		return('t');
// 	else if (file_stat.st_mode & S_IXOTH)
// 		return('x');
// 	else
// 		return('-');
// }

// static char get_group_x(struct stat file_stat)
// {
// 	if (!(file_stat.st_mode & S_IXGRP) && (file_stat.st_mode & S_ISGID))
// 		return('S');
// 	else if ((file_stat.st_mode & S_IXGRP) && (file_stat.st_mode & S_ISGID))
// 		return('s');
// 	else if (file_stat.st_mode & S_IXGRP)
// 		return('x');
// 	else
// 		return('-');
// }

// static char get_owner_x(struct stat file_stat)
// {
// 	if (!(file_stat.st_mode & S_IXUSR) && (file_stat.st_mode & S_ISUID))
// 		return('S');
// 	else if ((file_stat.st_mode & S_IXUSR) && (file_stat.st_mode & S_ISUID))
// 		return('s');
// 	else if (file_stat.st_mode & S_IXUSR)
// 		return('x');
// 	else
// 		return('-');
// }

// 	if (S_ISREG(st_mode))
// 		return ('-');
// 	if (S_ISDIR(st_mode))
// 		return ('d');
// 	if (S_ISCHR(st_mode))
// 		return ('c');
// 	if (S_ISBLK(st_mode))
// 		return ('b');
// 	if (S_ISFIFO(st_mode))
// 		return ('p');
// 	if (S_ISLNK(st_mode))
// 		return ('l');
// 	if (S_ISSOCK(st_mode))
// 		return ('s');
// 	return ('?');

// char			*print_color(t_file *file_stat)
// {
// 	if (S_ISDIR(file_stat.st_mode) && file_stat.st_mode & S_IWOTH &&
// 		(get_other_x(file_stat) == 't' || get_other_x(file_stat) == 'T'))
// 		return ("\033[38;5;000m\033[48;5;002m");
// 	if (S_ISDIR(file_stat.st_mode) && file_stat.st_mode & S_IWOTH)
// 		return ("\033[38;5;000m\033[48;5;003m");
// 	if (S_ISDIR(file_stat.st_mode))
// 		return ("\033[38;5;014m");
// 	if (S_ISLNK(file_stat.st_mode))
// 		return ("\033[38;5;005m");
// 	if (S_ISSOCK(file_stat.st_mode))
// 		return ("\033[38;5;002m");
// 	if (S_ISFIFO(file_stat.st_mode))
// 		return ("\033[38;5;011m");
// 	if (S_ISBLK(file_stat.st_mode))
// 		return ("\033[38;5;004m\033[48;5;006m");
// 	if (S_ISCHR(file_stat.st_mode))
// 		return ("\033[38;5;004m\033[48;5;003m");
// 	if (get_owner_x(file_stat) == 's' || get_owner_x(file_stat) == 'S')
// 		return ("\033[38;5;000m\033[48;5;001m");
// 	if (get_group_x(file_stat) == 's' || get_group_x(file_stat) == 'S')
// 		return ("\033[38;5;000m\033[48;5;006m");
// 	if (ft_strfind(file_data->modes, 'x') != -1)
// 		return ("\033[38;5;001m");
// 	return ("\033[38;5;007m");
// }



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
static int get_index(struct stat file_stat)
{
	if (S_ISLNK(file_stat.st_mode))
		return (2); // 2
	else if (S_ISSOCK(file_stat.st_mode))
		return (4); // 3
	else if (S_ISFIFO(file_stat.st_mode))
		return (6); // 4
	else if (S_ISBLK(file_stat.st_mode))
		return (10); // 6
	else if (S_ISCHR(file_stat.st_mode))
		return (12); // 7
	else if (S_ISDIR(file_stat.st_mode) && (file_stat.st_mode & S_IWOTH) && (file_stat.st_mode & S_ISVTX))
		return (18); //10
	else if (S_ISDIR(file_stat.st_mode) && (file_stat.st_mode & S_IWOTH))
		return (20); //11
	else if (S_ISDIR(file_stat.st_mode))
		return (0); // 1
	else if ((file_stat.st_mode & S_IXUSR) && (file_stat.st_mode & S_ISUID))
		return (14); // 8
	else if ((file_stat.st_mode & S_IXUSR) && (file_stat.st_mode & S_ISGID))
		return (16); // 9
	else if (file_stat.st_mode & S_IXUSR)
		return (8); // 5
	else
		return (-1);
	
}


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

	i = get_index(file_stat);
	if (i == -1)
		return (buff);
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
