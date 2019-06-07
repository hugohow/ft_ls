/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:11:35 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/06 15:43:59 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
size_t			ft_strlen(const char *str);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t len);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *str, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *str1, char const *str2);
char			*ft_strtrim(char const *str);
char			**ft_strsplit(char const *str, char c);
char			*ft_itoa(int nb);
char			*ft_ulltoa(unsigned long long nb);
void			ft_putchar(char c);
void			ft_putstr(char const *str);
void			ft_putendl(char const *str);
void			ft_putnbr(int nb);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *str, int fd);
void			ft_putendl_fd(char const *str, int fd);
void			ft_putnbr_fd(int nb, int fd);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstadd(t_list **alst, t_list *new_el);
void			ft_lstfree(t_list *head);
t_list			*ft_lstpop(t_list **p_head, void (*del)(void *, size_t));
t_list			*ft_lstpeek(t_list *head, int (*cmp)(t_list *n1, t_list *n2));
size_t			ft_lstlen(t_list *head);
t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstpush(t_list **head, void const *data, size_t data_size);
t_list			*ft_lst_insertafter(t_list **head, void const *content, \
	size_t content_size);
char			*ft_convert_base(char *decimal, char *base);
wchar_t			*ft_wstrjoin(wchar_t const *str1, wchar_t const *str2);
size_t			ft_wcslen(const wchar_t *str);
void			ft_wputchar(wchar_t c);
void			ft_wputstr(wchar_t const *str);
wchar_t			*ft_wstrsub(wchar_t const *str, unsigned int start, size_t len);
char			*ft_strcat_r(const char *src, char *dst);
char			*ft_str_insert(char *str, char c, int index);
char			*ft_str_left_shift(char *str, int len);
char			*ft_str_right_shift(char *str, int len);

char			*ft_bigint_add(char *dst, const char *to_add, size_t limit);
char			*ft_bigint_divide_by_two(char *output, size_t limit);
char			*ft_bigint_multiply_by_two(char *output, size_t limit);
char			*ft_bigint_shift_right(char *str, size_t nb, size_t limit);
char			*ft_bigint_trim(char *str);
char			*ft_bigint_round(char *dst, int precision, size_t limit);
int				ft_bigint_get_index(char *str, char c);

#endif
