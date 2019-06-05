/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_f_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 22:54:43 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 12:14:40 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*g_half_powers[] =
{
	H0,
	H1,
	H2,
	H3,
	H4,
	H5,
	H6,
	H7,
	H8,
	H9,
	H10,
	H11,
	H12,
	H13,
	H14,
	H15,
	H16,
	H17,
	H18,
	H19,
	H20,
	H21,
	H22,
	H23,
	H24,
	H25,
	H26,
	H27,
	H28,
	H29,
	H30,
	H31,
	H32,
	H33,
	H34,
	H35,
	H36,
	H37,
	H38,
	H39,
	H40,
	H41,
	H42,
	H43,
	H44,
	H45,
	H46,
	H47,
	H48,
	H49,
	H50,
	H51,
	H52,
	H53,
	H54,
	H55,
	H56,
	H57,
	H58,
	H59,
	H60,
	H61,
	H62,
	H63,
	H64,
	0,
};

static int	get_exponent(char *bin_floating_point)
{
	int				exponent;
	int				i;
	int				in;

	i = 1;
	exponent = 0;
	in = 16384;
	while (i < 16)
	{
		if (bin_floating_point[i] == '1')
			exponent += in * 1;
		in /= 2;
		i++;
	}
	return (exponent - 16383);
}

static char	*get_dec_mantissa(\
	char *str, char **p_output, size_t size_allocation)
{
	int				i;

	i = 0;
	*p_output = ft_strcpy(*p_output, "1");
	while (str[i])
	{
		if (i == 64)
			break ;
		if (str[i] == '1')
			*p_output = ft_bigint_add(\
				*p_output, g_half_powers[i + 1], size_allocation);
		i++;
	}
	if (ft_strcmp(*p_output, "1") == 0)
		*p_output = ft_strcpy(*p_output, "0");
	return (*p_output);
}

static char	*ft_infnity_or_nan(char *output, t_flag *flag)
{
	if (ft_strcmp(output, "0") == 0)
	{
		output = ft_strcpy(output, "inf");
		flag->zero = 0;
	}
	else
	{
		output = ft_strcpy(output, "nan");
		flag->zero = 0;
		flag->plus = 0;
		flag->plus = 0;
		flag->space = 0;
	}
	return (output);
}

static char	*get_decimal_str(char *output, int size_allocation, int expo)
{
	while (expo != 0)
	{
		if (expo < 0)
		{
			output = ft_bigint_divide_by_two(output, size_allocation);
			expo++;
		}
		else
		{
			output = ft_bigint_multiply_by_two(output);
			expo--;
		}
	}
	return (output);
}

char		*ft_fltoa(long double nb, char *str, t_flag *flag, int size)
{
	char			*output;
	int				expo;

	expo = get_exponent(str);
	if (!(output = (char *)ft_memalloc(size * sizeof(char))))
		return (NULL);
	output = get_dec_mantissa(str + 17, &output, size);
	if (nb == 0)
		output = ft_strcpy(output, "0.");
	else if (expo == 16384)
		output = ft_infnity_or_nan(output, flag);
	else if (expo == 0)
		output = ft_strcpy(output, "1.");
	else if (expo != -16382)
		output = get_decimal_str(output, size, expo);
	return (output);
}
