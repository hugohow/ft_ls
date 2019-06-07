/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 00:54:51 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/07 16:20:57 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	raise_error(char option)
{
	ft_dprintf(2, "ls: illegal option -- %c\n", option);
	ft_dprintf(2, \
		"usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n");
	return (-1);
}

static long	solve_mismatch(long flag)
{
	if (flag & FLAG_F)
	{
		flag |= FLAG_A;
		flag &= ~(FLAG_R | FLAG_CAP_S);
	}
	if (flag & FLAG_G)
		flag |= FLAG_L;
	if (flag & FLAG_D)
		flag &= ~FLAG_R;
	return (flag);
}

static const t_letter_flag	g_letter_flag[] =
{
	{'a', FLAG_A},
	{'l', FLAG_L},
	{'r', FLAG_R},
	{'R', FLAG_CAP_R},
	{'t', FLAG_T},
	{'g', FLAG_G},
	{'u', FLAG_U},
	{'d', FLAG_D},
	{'f', FLAG_F},
	{'S', FLAG_CAP_S},
	{'i', FLAG_I},
	{'G', FLAG_CAP_G},
	{'1', FLAG_ONE},
	{0, 0},
};

static long	ft_get_flag(char key)
{
	int k;

	k = 0;
	while (g_letter_flag[k].key)
	{
		if (g_letter_flag[k].key == key)
			return (g_letter_flag[k].flag);
		k++;
	}
	return (-1);
}

static int	ft_parse_arg(char *str, long *p_flag)
{
	int		j;
	long	ret;

	j = 1;
	while (str[j])
	{
		if ((ret = ft_get_flag(str[j])) == -1)
			return (raise_error(str[j]));
		else
			*p_flag |= ret;
		j++;
	}
	return (0);
}

long		ft_parse_input(char ***p_argv)
{
	long	flag;

	flag = 0;
	while (**p_argv && (**p_argv)[0] == '-')
	{
		if ((**p_argv)[0] == '-' && (**p_argv)[1] == 0)
			return (flag);
		if ((**p_argv)[0] == '-' && \
			(**p_argv)[1] == '-' && (**p_argv)[2] == 0)
		{
			*p_argv = *p_argv + 1;
			return (flag);
		}
		if (ft_parse_arg(**p_argv, &flag) == -1)
			return (-1);
		*p_argv = *p_argv + 1;
	}
	return (solve_mismatch(flag));
}
