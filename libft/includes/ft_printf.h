/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 22:50:40 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/10 20:19:00 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include "libft.h"
# define PREFIX_0X_MAJ "0X"
# define PREFIX_0X "0x"
# define PREFIX_0 "0"
# define BASE_O "01234567"
# define BASE_X "0123456789abcdef"
# define BASE_X_MAJ "0123456789ABCDEF"
# define BASE_B "01"
# define PERCENTAGE "%"
# define ANSI_COLOR_CYAN "\x1b[36m"
# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_YELLOW "\x1b[33m"
# define ANSI_COLOR_BLUE "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_RESET "\x1b[0m"
# define LENGTH_H (1 << 1)
# define LENGTH_HH (1 << 2)
# define LENGTH_L (1 << 3)
# define LENGTH_LL (1 << 4)
# define LENGTH_J (1 << 5)
# define LENGTH_Z (1 << 6)
# define LENGTH_L_MAJ (1 << 7)
# define KEY_PERCENTAGE (1 << 1)
# define KEY_C (1 << 2)
# define KEY_D (1 << 3)
# define KEY_NB (1 << 4)
# define KEY_P (1 << 5)
# define KEY_S (1 << 6)
# define KEY_F (1 << 7)
# define KEY_E (1 << 8)
# define MAX_ALLOCATION_LFLOAT 5000
# define MAX_ALLOCATION_FLOAT 1024
# define H0 "1"
# define H1 "0.5"
# define H2 "0.25"
# define H3 "0.125"
# define H4 "0.0625"
# define H5 "0.03125"
# define H6 "0.015625"
# define H7 "0.0078125"
# define H8 "0.00390625"
# define H9 "0.001953125"
# define H10 "0.0009765625"
# define H11 "0.00048828125"
# define H12 "0.000244140625"
# define H13 "0.0001220703125"
# define H14 "0.00006103515625"
# define H15 "0.000030517578125"
# define H16 "0.0000152587890625"
# define H17 "0.00000762939453125"
# define H18 "0.000003814697265625"
# define H19 "0.0000019073486328125"
# define H20 "0.00000095367431640625"
# define H21 "0.000000476837158203125"
# define H22 "0.0000002384185791015625"
# define H23 "0.00000011920928955078125"
# define H24 "0.000000059604644775390625"
# define H25 "0.0000000298023223876953125"
# define H26 "0.00000001490116119384765625"
# define H27 "0.000000007450580596923828125"
# define H28 "0.0000000037252902984619140625"
# define H29 "0.00000000186264514923095703125"
# define H30 "0.000000000931322574615478515625"
# define H31 "0.0000000004656612873077392578125"
# define H32 "0.00000000023283064365386962890625"
# define H33 "0.000000000116415321826934814453125"
# define H34 "0.0000000000582076609134674072265625"
# define H35 "0.00000000002910383045673370361328125"
# define H36 "0.000000000014551915228366851806640625"
# define H37 "0.0000000000072759576141834259033203125"
# define H38 "0.00000000000363797880709171295166015625"
# define H39 "0.000000000001818989403545856475830078125"
# define H40 "0.0000000000009094947017729282379150390625"
# define H41 "0.00000000000045474735088646411895751953125"
# define H42 "0.000000000000227373675443232059478759765625"
# define H43 "0.0000000000001136868377216160297393798828125"
# define H44 "0.00000000000005684341886080801486968994140625"
# define H45 "0.000000000000028421709430404007434844970703125"
# define H46 "0.0000000000000142108547152020037174224853515625"
# define H47 "0.00000000000000710542735760100185871124267578125"
# define H48 "0.000000000000003552713678800500929355621337890625"
# define H49 "0.0000000000000017763568394002504646778106689453125"
# define H50 "0.00000000000000088817841970012523233890533447265625"
# define H51 "0.000000000000000444089209850062616169452667236328125"
# define H52 "0.0000000000000002220446049250313080847263336181640625"
# define H53 "0.00000000000000011102230246251565404236316680908203125"
# define H54 "0.000000000000000055511151231257827021181583404541015625"
# define H55 "0.0000000000000000277555756156289135105907917022705078125"
# define H56 "0.00000000000000001387778780781445675529539585113525390625"
# define H57 "0.000000000000000006938893903907228377647697925567626953125"
# define H58 "0.0000000000000000034694469519536141888238489627838134765625"
# define H59 "0.00000000000000000173472347597680709441192448139190673828125"
# define H60 "0.000000000000000000867361737988403547205962240695953369140625"
# define H61 "0.0000000000000000004336808689942017736029811203479766845703125"
# define H62 "0.00000000000000000021684043449710088680149056017398834228515625"
# define H63 "0.000000000000000000108420217248550443400745280086994171142578125"
# define H64 "0.000000000000000000054210108624275221700372640043497085571289062"

typedef struct		s_flag
{
	int				key;
	int				length;
	char			conv;
	int				precision;
	unsigned int	width;
	int				zero;
	int				plus;
	int				minus;
	int				space;
	int				hash;
	char			character;
	int				character_i;
	size_t			size_allocation;
}					t_flag;

typedef char		*(t_ft)(va_list *, t_flag *);
typedef struct		s_ft_print
{
	int				key;
	int				length;
	t_ft			*fct;
}					t_ft_print;

typedef struct		s_color
{
	char			key[10];
	char			str[10];
}					t_color;

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_sprintf(char *str, const char *format, ...);
char				*ft_str_join_r(char *str1, const char *add, t_flag *flag);
char				*ft_str_join(const char *add, char *str1, t_flag *flag);
char				*ft_get_color(const char *str);
char				*ft_itoa_ll(long long nb);
size_t				ft_flaglen(const char *str);
char				*ft_apply_padding_p(char *str, t_flag *f, int s);
char				*ft_apply_padding_nb(char *str, t_flag *flag, int sign);
char				*ft_apply_padding_str(char *str, t_flag *flag, int sign);
char				*ft_apply_padding_e(char *str, t_flag *f, int sign, int e);
char				*ft_apply_precision_nb(char *str, t_flag *flag, int sign);
char				*ft_apply_precision_str(char *str, t_flag *flag, int sign);
char				*ft_apply_precision_p(char *str, int precision);
int					get_length(char *flag);
char				*ft_printf_arg(va_list *ap, t_flag *flag);
t_flag				*ft_create_flag(char *str, va_list *p_ap);
int					ft_flag_get_space(char *flag);
int					ft_flag_get_hash(char *flag);
int					ft_flag_get_length(char *flag);
int					ft_flag_get_minus(char *flag);
int					ft_flag_get_plus(char *flag);
int					ft_flag_get_precision(char *flag, va_list *p_ap);
int					ft_flag_get_width(char *str, va_list *p_ap, t_flag *flag);
int					ft_flag_get_zero(char *flag);
int					ft_flag_get_key(char *flag);
char				*ft_add_char(char *str, t_flag *flag, char c);
char				*ft_strcat(char *s1, const char *s2);
int					ft_len_to_alloc(size_t original_nblen, t_flag *flag);
char				*ft_print_d(va_list *ap, t_flag *flag);
char				*ft_print_d_l(va_list *ap, t_flag *flag);
char				*ft_print_d_ll(va_list *ap, t_flag *flag);
char				*ft_print_d_h(va_list *ap, t_flag *flag);
char				*ft_print_d_hh(va_list *ap, t_flag *flag);
char				*ft_print_percent(va_list *ap, t_flag *flag);
char				*ft_print_nb(va_list *ap, t_flag *flag);
char				*ft_print_nb_l(va_list *ap, t_flag *flag);
char				*ft_print_nb_ll(va_list *ap, t_flag *flag);
char				*ft_print_nb_hh(va_list *ap, t_flag *flag);
char				*ft_print_nb_h(va_list *ap, t_flag *flag);
char				*ft_print_f(va_list *ap, t_flag *flag);
char				*ft_print_f_l(va_list *ap, t_flag *flag);
char				*ft_print_f_l_maj(va_list *ap, t_flag *flag);
char				*ft_print_e(va_list *ap, t_flag *flag);
char				*ft_print_e_l(va_list *ap, t_flag *flag);
char				*ft_print_e_l_maj(va_list *ap, t_flag *flag);
char				*ft_print_s(va_list *ap, t_flag *flag);
char				*ft_print_c(va_list *ap, t_flag *flag);
char				*ft_print_p(va_list *ap, t_flag *flag);
char				*ft_convert_output(char *str, t_flag *flag);
size_t				ft_nblen_ull(unsigned long long nb);
char				*ft_ulltoa_offset(unsigned long long nb, size_t size);
int					ft_str_precision_count(char *str, int offset);
char				*ft_fltoa(long double nb, char *str, t_flag *flag, int s);
char				*ft_ftoa(double nb, char *str, t_flag *flag, int s);
char				*ft_get_binary(unsigned char c, char *tmp_str);
int					ft_can_apply_plus(t_flag *flag, int sign);
int					ft_can_apply_space(t_flag *flag, int sign);
int					ft_can_apply_prefix(t_flag *flag, int sign);
int					ft_can_apply_minus(t_flag *flag, int sign);
int					ft_can_fill_to_the_left(t_flag *flag, int sign);
int					ft_can_fill_to_the_right(t_flag *flag, int sign);
int					ft_can_fill_with_zeros(t_flag *flag, int sign);
int					ft_can_fill_with_zeros_float(t_flag *flag, int sign);
char				*ft_strdup_alloc(const char *s1, size_t size_allocation);
int					ft_print_null(char *output, t_flag *flag, int fd);
char				*ft_strcat_char(char *s1, const char c);
int					ft_format_is_valid(const char *format);
char				*ft_itoa_e(int nb);
int					ft_apply_e(char *output);
#endif
