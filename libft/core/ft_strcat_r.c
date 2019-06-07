/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:56:50 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/05 13:02:04 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat_r(const char *src, char *dst)
{
	char *tmp;

	tmp = ft_strdup(dst);
	if (tmp == NULL)
		return (NULL);
	ft_strcpy(dst, src);
	ft_strcat(dst, tmp);
	ft_memdel((void **)&tmp);
	return (dst);
}
