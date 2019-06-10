/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 21:13:47 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/10 20:10:42 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse_cat(char *f, va_list *ap, size_t *plen, char *str)
{
	int		len;
	t_flag	*flag;
	char	*output;

	len = 0;
	if (!(flag = ft_create_flag(f, ap)))
		return (-1);
	output = ft_printf_arg(ap, flag);
	if (output == NULL)
		return (-1);
	if (flag->character == 0)
	{
		ft_memmove(str + *plen, output, ft_strlen(output));
		*plen = *plen + ft_strlen(output);
		str[*plen] = '\0';
	}
	else
	{
		ft_memmove(str + *plen, output, ft_strlen(output));
		*plen = *plen + ft_strlen(output);
	}
	ft_memdel((void **)&flag);
	ft_memdel((void **)&output);
	return (0);
}

static void	ft_cat_gen(const char *format, int *p_i, size_t *p_len, char *str)
{
	char *color;

	color = NULL;
	if (format[*p_i] == '{' && (\
		color = ft_get_color(format + *p_i + 1)) != 0)
	{
		ft_memmove(str + *p_len, color, ft_strlen(color));
		*p_i = *p_i + 1;
		while (format[*p_i] && format[*p_i] != '}')
			*p_i = *p_i + 1;
	}
	else
	{
		ft_memmove(str + *p_len, &format[*p_i], 1);
		*p_len = *p_len + 1;
	}
}

static int	ft_cat(const char *format, size_t *p_len, va_list *ap, char *str)
{
	char				*flag;

	if (!(flag = (char *)ft_memalloc((ft_strlen(format) + 1) * sizeof(char))))
		return (-1);
	flag = ft_strncpy(flag, format, (int)ft_flaglen(format) + 1);
	if (ft_parse_cat(flag, ap, p_len, str) == -1)
	{
		ft_memdel((void **)&flag);
		return (-1);
	}
	ft_memdel((void **)&flag);
	return ((int)ft_flaglen(format));
}

int			ft_sprintf(char *str, const char *format, ...)
{
	va_list				ap;
	int					i;
	size_t				len;
	int					ret;

	if (ft_format_is_valid(format) == 0)
		return (0);
	va_start(ap, format);
	i = -1;
	len = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			ret = ft_cat(format + i, &len, &ap, str);
			if (ret == -1)
				i += (int)ft_flaglen(format + i) - 1;
			else
				i += ret;
		}
		else
			ft_cat_gen(format, &i, &len, str);
	}
	va_end(ap);
	return (len);
}
