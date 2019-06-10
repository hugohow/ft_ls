/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_acl_attr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 02:48:07 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/10 22:42:38 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_acl_attr(t_content *content)
{
	if (content->has_acl && content->has_extended_attributes)
		ft_putchar_fd('@', 1);
	else if (content->has_acl)
		ft_putchar_fd('+', 1);
	else if (content->has_extended_attributes)
		ft_putchar_fd('@', 1);
	else
		ft_putchar_fd(' ', 1);
}
