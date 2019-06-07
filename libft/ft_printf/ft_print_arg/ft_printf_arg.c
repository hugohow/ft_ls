/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:20:38 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/07 12:04:05 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const	t_ft_print g_fts_print[] =
{
	{KEY_PERCENTAGE, 0, &ft_print_percent},
	{KEY_C, 0, &ft_print_c},
	{KEY_S, 0, &ft_print_s},
	{KEY_P, 0, &ft_print_p},
	{KEY_D, 0, &ft_print_d},
	{KEY_D, LENGTH_H, &ft_print_d_h},
	{KEY_D, LENGTH_HH, &ft_print_d_hh},
	{KEY_D, LENGTH_L, &ft_print_d_l},
	{KEY_D, LENGTH_LL, &ft_print_d_ll},
	{KEY_NB, 0, &ft_print_nb},
	{KEY_NB, LENGTH_H, &ft_print_nb_h},
	{KEY_NB, LENGTH_HH, &ft_print_nb_hh},
	{KEY_NB, LENGTH_L, &ft_print_nb_l},
	{KEY_NB, LENGTH_LL, &ft_print_nb_ll},
	{KEY_F, 0, &ft_print_f},
	{KEY_F, LENGTH_L, &ft_print_f_l},
	{KEY_F, LENGTH_L_MAJ, &ft_print_f_l_maj},
	{KEY_E, 0, &ft_print_e},
	{KEY_E, LENGTH_L, &ft_print_e_l},
	{KEY_E, LENGTH_L_MAJ, &ft_print_e_l_maj},
	{0, 0, NULL},
};

t_ft	*ft_find_print(t_flag *flag)
{
	int			i;
	int			j;

	i = 0;
	while (g_fts_print[i].key)
	{
		if (g_fts_print[i].key == flag->key)
		{
			j = i;
			while (g_fts_print[j].key && g_fts_print[j].key == flag->key)
			{
				if (g_fts_print[j].length == flag->length)
					return (g_fts_print[j].fct);
				j++;
			}
			return (g_fts_print[i].fct);
		}
		i++;
	}
	return (NULL);
}

char	*ft_printf_arg(va_list *ap, t_flag *flag)
{
	t_ft		*fct;
	char		*ret;

	fct = ft_find_print(flag);
	ret = 0;
	if (fct != NULL)
	{
		ret = fct(ap, flag);
		if (ret == NULL)
		{
			ft_memdel((void **)&flag);
			return (NULL);
		}
	}
	return (ret);
}
