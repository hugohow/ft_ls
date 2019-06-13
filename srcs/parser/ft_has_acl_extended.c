/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_acl_extended.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 17:45:20 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/13 12:14:49 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	has_extended_attributes(const char *path)
{
	ssize_t len;
#ifdef __APPLE__
	len = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
#else
	len = listxattr(path, NULL, 0);
#endif
	if (len > 0)
		return (1);
	return (0);
}

int	has_acl(const char *path)
{
	acl_t acl;

	acl = acl_get_file(path, ACL_TYPE_ACCESS);
	if (acl)
	{
		acl_free((void *)acl);
		return (1);
	}
	acl_free((void *)acl);
	return (0);
}
