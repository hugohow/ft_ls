/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 21:10:04 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/10 20:03:53 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parseprint(char *flag_line, va_list *p_ap, size_t *p_len, int fd)
{
	int		len;
	t_flag	*flag;
	char	*output;

	len = 0;
	if (!(flag = ft_create_flag(flag_line, p_ap)))
		return (-1);
	output = ft_printf_arg(p_ap, flag);
	if (output == NULL)
		return (-1);
	if (flag->character == 0 && flag->key & KEY_C)
		*p_len = *p_len + (size_t)ft_print_null(output, flag, fd);
	else
	{
		ft_putstr_fd(output, fd);
		*p_len = *p_len + ft_strlen(output);
	}
	ft_memdel((void **)&flag);
	ft_memdel((void **)&output);
	return (0);
}

static void	ft_print_gen(const char *format, int *p_i, size_t *p_len, int fd)
{
	char *color;

	color = NULL;
	if (format[*p_i] == '{' && (\
		color = ft_get_color(format + *p_i + 1)) != 0)
	{
		ft_putstr_fd(color, fd);
		*p_i = *p_i + 1;
		while (format[*p_i] && format[*p_i] != '}')
			*p_i = *p_i + 1;
	}
	else
	{
		ft_putchar_fd(format[*p_i], fd);
		*p_len = *p_len + 1;
	}
}

static int	ft_print(const char *str, size_t *p_len, va_list *p_ap, int fd)
{
	char				*flag;

	if (!(flag = (char *)ft_memalloc((ft_strlen(str) + 1) * sizeof(char))))
		return (-1);
	flag = ft_strncpy(flag, str, (int)ft_flaglen(str) + 1);
	if (ft_parseprint(flag, p_ap, p_len, fd) == -1)
	{
		ft_memdel((void **)&flag);
		return (-1);
	}
	ft_memdel((void **)&flag);
	return ((int)ft_flaglen(str));
}

int			ft_dprintf(int fd, const char *format, ...)
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
			ret = ft_print(format + i, &len, &ap, fd);
			if (ret == -1)
				i += (int)ft_flaglen(format + i) - 1;
			else
				i += ret;
		}
		else
			ft_print_gen(format, &i, &len, fd);
	}
	va_end(ap);
	return (len);
}
