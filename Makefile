# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/02 19:55:06 by hhow-cho          #+#    #+#              #
#    Updated: 2019/06/13 14:08:43 by hhow-cho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=		ft_ls
CC			= 		gcc
ifeq ($(UNAME_S),Darwin)
CFLAGS 		= 		-Iincludes -Wall -Werror -Wextra
else
CFLAGS 		= 		-Iincludes -Wall -Wextra
endif
OBJ 		= 		$(SRC:.c=.o)

C_OK		=		"\033[35m"
C_GOOD		=		"\033[32m"
C_NO		=		"\033[00m"

SUCCESS		=		$(C_GOOD)SUCCESS$(C_NO)
OK			=		$(C_OK)OK$(C_NO)

DEBUG = #-g3 -fsanitize=address

SRC =	srcs/ft_ls.c   \
		srcs/parser/ft_create_content.c   \
		srcs/parser/ft_has_acl_extended.c   \
		srcs/parser/ft_parse_input.c   \
		srcs/parser/ft_get_default_values.c   \
		srcs/print_file/ft_print_acl_attr.c   \
		srcs/print_file/ft_print_date.c   \
		srcs/print_file/ft_print_datum.c   \
		srcs/print_file/ft_print_file_stat.c   \
		srcs/print_file/ft_print_file_stat_long.c   \
		srcs/print_file/ft_print_mode.c   \
		srcs/print_file/ft_print_path.c   \
		srcs/tree/ft_del_tree.c   \
		srcs/tree/ft_fill_tree.c   \
		srcs/tree/ft_print_full_tree.c   \
		srcs/tree/ft_print_full_tree_err.c   \
		srcs/tree/ft_print_tree.c   \
		srcs/utils/ft_browse_dir.c   \
		srcs/utils/ft_get_color.c   \
		srcs/utils/ft_get_current_dir.c   \
		srcs/utils/ft_get_file_name.c   \
		srcs/utils/ft_nodecmp.c   \
		srcs/utils/ft_print_content.c   \
		srcs/utils/ft_info_file.c

all: $(NAME)

%.o: %.c
	@printf "[ft_ls] Compiling [.:]\r"
	@$(CC) $(CFLAGS) -c $< -lacl -o $@
	@printf "[ft_ls] Compiling [:.]\r"

$(NAME): $(OBJ)
	@make -C libft/
	@echo "Creating" [ $(NAME) ]
	@$(CC) $(CFLAGS) $(INCLUDES) $^ -lacl libft/libft.a -o $(NAME)
	@echo "Creation" [ $(NAME) ] $(SUCCESS)

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJ)
	@printf "[ft_ls] Removed object files!\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft/
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)
	
re: fclean all

ifeq ($(shell uname),Darwin)
test: re
	sh test.sh
else
test: re
	@echo "\n\n\033[45mBuild ok, launch tests on OSX\033[0m\n\n"
	exit 0
endif

.PHONY: all clean fclean re test