/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:10:40 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/31 12:10:54 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_color	g_tab_colors[] =
{
	{"cyan", ANSI_COLOR_CYAN},
	{"red", ANSI_COLOR_RED},
	{"green", ANSI_COLOR_GREEN},
	{"yellow", ANSI_COLOR_YELLOW},
	{"blue", ANSI_COLOR_BLUE},
	{"magenta", ANSI_COLOR_MAGENTA},
	{"eoc", ANSI_COLOR_RESET},
	{"", ""},
};

char					*ft_get_color(const char *str)
{
	int					len;
	int					i;

	len = 0;
	i = 0;
	while (str[len] && str[len] != '}')
		len++;
	if (len == 0)
		return (NULL);
	while ((g_tab_colors[i].key)[0])
	{
		if (ft_strncmp(g_tab_colors[i].key, str, len) == 0)
		{
			return ((char *)g_tab_colors[i].str);
		}
		i++;
	}
	return (NULL);
}
