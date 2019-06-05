/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_alloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 11:19:46 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/02 11:20:27 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strdup_alloc(const char *s1, size_t size_allocation)
{
	char	*copy;

	if (!(copy = (char *)malloc((size_allocation) * sizeof(char))))
		return (NULL);
	copy = ft_strcpy(copy, s1);
	return (copy);
}
