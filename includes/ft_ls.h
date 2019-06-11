/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:45:03 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/11 19:16:47 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/types.h>
# include <sys/acl.h>
# include "libft.h"
# include "avltree.h"
# include "queue.h"
# define FLAG_A (1 << 0)
# define FLAG_L (1 << 1)
# define FLAG_R (1 << 2)
# define FLAG_CAP_R (1 << 3)
# define FLAG_T (1 << 4)
# define FLAG_G (1 << 5)
# define FLAG_U (1 << 6)
# define FLAG_F (1 << 7)
# define FLAG_D (1 << 8)
# define FLAG_CAP_S (1 << 9)
# define FLAG_I (1 << 10)
# define FLAG_CAP_G (1 << 11)
# define FLAG_ONE (1 << 12)
# define FLAG_CAP_U (1 << 13)
# define FLAG_O (1 << 14)
# define FLAG_N (1 << 15)
# define SIXMONTHS ((365 / 2) * 86400)
# define ANSI_COLOR_FG_BLACK "\x1b[30m"
# define ANSI_COLOR_FG_RED "\x1b[31m"
# define ANSI_COLOR_FG_GREEN "\x1b[32m"
# define ANSI_COLOR_FG_BROWN "\x1b[33m"
# define ANSI_COLOR_FG_BLUE "\x1b[34m"
# define ANSI_COLOR_FG_MAGENTA "\x1b[35m"
# define ANSI_COLOR_FG_CYAN "\x1b[36m"
# define ANSI_COLOR_FG_WITHE "\x1b[37m"
# define ANSI_COLOR_FG_BOLD_BLACK "\x1b[90m"
# define ANSI_COLOR_FG_BOLD_RED "\x1b[91m"
# define ANSI_COLOR_FG_BOLD_GREEN "\x1b[92m"
# define ANSI_COLOR_FG_BOLD_BROWN "\x1b[93m"
# define ANSI_COLOR_FG_BOLD_BLUE "\x1b[94m"
# define ANSI_COLOR_FG_BOLD_MAGENTA "\x1b[95m"
# define ANSI_COLOR_FG_BOLD_CYAN "\x1b[96m"
# define ANSI_COLOR_FG_BOLD_GREY "\x1b[97m"
# define ANSI_COLOR_BG_BLACK "\x1b[40m"
# define ANSI_COLOR_BG_RED "\x1b[41m"
# define ANSI_COLOR_BG_GREEN "\x1b[42m"
# define ANSI_COLOR_BG_BROWN "\x1b[43m"
# define ANSI_COLOR_BG_BLUE "\x1b[44m"
# define ANSI_COLOR_BG_MAGENTA "\x1b[45m"
# define ANSI_COLOR_BG_CYAN "\x1b[46m"
# define ANSI_COLOR_BG_WITHE "\x1b[47m"
# define ANSI_COLOR_BG_BOLD_BLACK "\x1b[100m"
# define ANSI_COLOR_BG_BOLD_RED "\x1b[101m"
# define ANSI_COLOR_BG_BOLD_GREEN "\x1b[102m"
# define ANSI_COLOR_BG_BOLD_BROWN "\x1b[103m"
# define ANSI_COLOR_BG_BOLD_BLUE "\x1b[104m"
# define ANSI_COLOR_BG_BOLD_MAGENTA "\x1b[105m"
# define ANSI_COLOR_BG_BOLD_CYAN "\x1b[106m"
# define ANSI_COLOR_BG_BOLD_GREY "\x1b[107m"
# define ANSI_COLOR_RESET "\x1b[0m"

typedef struct		s_content
{
	char			*path;
	char			*name;
	struct stat		file_stat;
	long			flag;
	long long		st_size;
	long			total_size;
	size_t			nb_files;
	size_t			len;
	int				level;
	long long		time;
	long long		sec;
	long long		nsec;
	int				has_extended_attributes;
	int				has_acl;
	unsigned long	st_mode;
	char			*error;
	char			*link;
	int				len_link;
	int				len_owner;
	int				len_group;
	int				len_size;
	int				len_uid;
	int				len_gid;
	int				len_major;
	int				len_minor;
	int				len_ino;
	char			*pw_name;
	char			*gr_name;
	t_node_avlt		*subtree;
}					t_content;

typedef struct		s_letter_flag
{
	char			key;
	long			flag;
}					t_letter_flag;

typedef struct		s_color
{
	char			key;
	char			str[10];
}					t_color;

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
long				ft_parse_input(char ***p_argv);
t_content			*ft_create_content(char *path, long flag, \
	int level, size_t len);
int					ft_can_browse_dir(t_content *content);
t_node_avlt			*ft_browse_dir(t_content *content, t_node_avlt **root_err);
void				ft_fill_tree_recursive(t_node_avlt **root, \
	t_content *content, t_node_avlt **root_err);
void				ft_fill_tree(t_node_avlt **root, t_content *content, \
	t_node_avlt **root_err);
char				*ft_get_file_name(t_content *content);
int					ft_nodecmp_date(t_node_avlt *node1, t_node_avlt *node2);
int					ft_nodecmp_path(t_node_avlt *node1, t_node_avlt *node2);
int					ft_nodecmp_unsorted(t_node_avlt *node1, t_node_avlt *node2);
int					ft_nodecmp_size(t_node_avlt *node1, t_node_avlt *node2);
void				ft_print_file_stat_long(t_content *ct, t_content *ct_r);
void				ft_print_full_tree(t_node_avlt *root, \
	int *p_ret, int *p_index_g, t_content *content_dir);
void				ft_print_full_tree_err(t_node_avlt *root);
void				ft_print_file_stat_long(t_content *ct, t_content *ct_r);
void				ft_print_file_stat(t_content *content, int index);
char				*ft_get_current_dir(const char *path, char *curr_dir);
int					has_extended_attributes(const char *path);
int					has_acl(const char *path);
void				ft_print_tree_reverse(t_node_avlt *root, \
	t_queue **p_queue, int *p_index_g, t_content *ct_r);
void				ft_print_tree(t_node_avlt *root, \
	t_queue **p_queue, int *p_index_g, t_content *ct_r);
void				ft_print_date(t_content *content);
void				ft_print_mode(t_content *content);
void				ft_print_acl_attr(t_content *content);
void				ft_print_datum(t_content *content, t_content *r);
void				ft_print_path(t_content *content);
void				ft_del_tree(t_node_avlt **p_root);
char				ft_get_letter_mode(unsigned long st_mode);
char				*ft_get_color_bg_fg(struct stat file_stat, char *buff);
void				ft_print_content(t_node_avlt *node, int i, t_content *ct_r);
t_content			*ft_get_default_values(t_content *content, long flag, \
	int level, size_t len);
char				*ft_get_file_name_raw(t_content *content);
int					file_is_hidden(char *name);
#endif
