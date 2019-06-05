# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/05 23:41:00 by hhow-cho          #+#    #+#              #
#    Updated: 2019/06/06 01:38:32 by hhow-cho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc $(FLAGS) -I includes
FLAGS	=	-Wall -Wextra -Werror
NAME	=	libft.a

SRCS	=	core/ft_memset.c					\
			core/ft_bzero.c					\
			core/ft_memcpy.c					\
			core/ft_memccpy.c				\
			core/ft_memmove.c				\
			core/ft_memchr.c					\
			core/ft_memcmp.c					\
			core/ft_strlen.c					\
			core/ft_strdup.c					\
			core/ft_strcpy.c					\
			core/ft_strncpy.c				\
			core/ft_strcat.c					\
			core/ft_strcat_r.c				\
			core/ft_strncat.c				\
			core/ft_strlcat.c				\
			core/ft_strchr.c					\
			core/ft_strrchr.c				\
			core/ft_strstr.c					\
			core/ft_strnstr.c				\
			core/ft_strcmp.c					\
			core/ft_strncmp.c				\
			core/ft_atoi.c					\
			core/ft_isalpha.c				\
			core/ft_isdigit.c				\
			core/ft_isalnum.c				\
			core/ft_isascii.c				\
			core/ft_isprint.c				\
			core/ft_toupper.c				\
			core/ft_tolower.c				\
			core/ft_memalloc.c				\
			core/ft_memdel.c					\
			core/ft_strnew.c					\
			core/ft_strdel.c					\
			core/ft_strclr.c					\
			core/ft_striter.c				\
			core/ft_striteri.c				\
			core/ft_strmap.c					\
			core/ft_strmapi.c				\
			core/ft_strequ.c					\
			core/ft_strnequ.c				\
			core/ft_strsub.c					\
			core/ft_strjoin.c				\
			core/ft_strtrim.c				\
			core/ft_strsplit.c				\
			core/ft_itoa.c					\
			core/ft_putchar.c				\
			core/ft_putchar_fd.c				\
			core/ft_putstr.c					\
			core/ft_putstr_fd.c				\
			core/ft_putendl.c				\
			core/ft_putendl_fd.c				\
			core/ft_putnbr.c					\
			core/ft_putnbr_fd.c				\
			core/ft_lstnew.c					\
			core/ft_lstdelone.c				\
			core/ft_lstdel.c					\
			core/ft_lstadd.c					\
			core/ft_lstiter.c				\
			core/ft_lstmap.c					\
			core/ft_lstpush.c				\
			core/ft_lstfree.c				\
			core/ft_lstpop.c					\
			core/ft_lstpeek.c				\
			core/ft_lstpush.c				\
			core/ft_lstlen.c					\
			bigint/ft_bigint_add.c				\
			bigint/ft_bigint_divide_by_two.c	\
			bigint/ft_bigint_get_index.c		\
			bigint/ft_bigint_multiply_by_two.c	\
			bigint/ft_bigint_round.c			\
			bigint/ft_bigint_shift_right.c		\
			bigint/ft_bigint_trim.c			\
			core/ft_convert_base.c			\
			core/ft_str_insert.c				\
			core/ft_str_left_shift.c			\
			core/ft_str_right_shift.c			\
			core/ft_ulltoa.c					\
			queue/ft_queue_dequeue.c					\
			queue/ft_queue_enqueue.c					\
			queue/ft_queue_init.c					\
		ft_printf/ft_dprintf.c						\
		ft_printf/ft_printf.c						\
		ft_printf/ft_sprintf.c						\
		ft_printf/ft_print_arg/ft_print_c.c			\
		ft_printf/ft_print_arg/ft_print_d.c			\
		ft_printf/ft_print_arg/ft_print_d_h.c		\
		ft_printf/ft_print_arg/ft_print_d_hh.c		\
		ft_printf/ft_print_arg/ft_print_d_l.c		\
		ft_printf/ft_print_arg/ft_print_d_ll.c		\
		ft_printf/ft_print_arg/ft_print_e.c			\
		ft_printf/ft_print_arg/ft_print_e_l.c		\
		ft_printf/ft_print_arg/ft_print_e_l_maj.c	\
		ft_printf/ft_print_arg/ft_print_f.c			\
		ft_printf/ft_print_arg/ft_print_f_l.c		\
		ft_printf/ft_print_arg/ft_print_f_l_maj.c	\
		ft_printf/ft_print_arg/ft_print_nb.c			\
		ft_printf/ft_print_arg/ft_print_nb_h.c		\
		ft_printf/ft_print_arg/ft_print_nb_hh.c		\
		ft_printf/ft_print_arg/ft_print_nb_l.c		\
		ft_printf/ft_print_arg/ft_print_nb_ll.c		\
		ft_printf/ft_print_arg/ft_print_p.c			\
		ft_printf/ft_print_arg/ft_print_percent.c	\
		ft_printf/ft_print_arg/ft_print_s.c			\
		ft_printf/ft_print_arg/ft_printf_arg.c		\
		ft_printf/helpers/ft_add_char.c				\
		ft_printf/helpers/ft_apply_e.c				\
		ft_printf/helpers/ft_condition_fill.c		\
		ft_printf/helpers/ft_condition_flag.c		\
		ft_printf/helpers/ft_convert_output.c		\
		ft_printf/helpers/ft_flaglen.c				\
		ft_printf/helpers/ft_format_is_valid.c		\
		ft_printf/helpers/ft_get_binary.c			\
		ft_printf/helpers/ft_get_color.c				\
		ft_printf/helpers/ft_itoa_e.c				\
		ft_printf/helpers/ft_itoa_f.c				\
		ft_printf/helpers/ft_itoa_f_l.c				\
		ft_printf/helpers/ft_nblen_ull.c				\
		ft_printf/helpers/ft_print_null.c			\
		ft_printf/helpers/ft_size_to_allocate.c		\
		ft_printf/helpers/ft_str_join.c				\
		ft_printf/helpers/ft_str_join_r.c			\
		ft_printf/helpers/ft_str_precision_count.c	\
		ft_printf/helpers/ft_strcat_char.c			\
		ft_printf/helpers/ft_strdup_alloc.c			\
		ft_printf/helpers/ft_ulltoa_offset.c			\
		ft_printf/padding/ft_apply_padding_e.c		\
		ft_printf/padding/ft_apply_padding_nb.c		\
		ft_printf/padding/ft_apply_padding_p.c		\
		ft_printf/padding/ft_apply_padding_str.c		\
		ft_printf/parser/ft_create_flag.c			\
		ft_printf/parser/ft_flag_create_space.c		\
		ft_printf/parser/ft_flag_get_hash.c			\
		ft_printf/parser/ft_flag_get_key.c			\
		ft_printf/parser/ft_flag_get_length.c		\
		ft_printf/parser/ft_flag_get_minus.c			\
		ft_printf/parser/ft_flag_get_plus.c			\
		ft_printf/parser/ft_flag_get_precision.c		\
		ft_printf/parser/ft_flag_get_width.c			\
		ft_printf/parser/ft_flag_get_zero.c			\
		ft_printf/precision/ft_apply_precision_nb.c	\
		ft_printf/precision/ft_apply_precision_str.c	\
		avlt/ft_avlt_add.c		\
		avlt/ft_avlt_apply_inorder.c		\
		avlt/ft_avlt_apply_postorder.c		\
		avlt/ft_avlt_create.c		\
		avlt/ft_avlt_free.c		\
		avlt/ft_avlt_insert.c		\
		avlt/ft_avlt_is_valid.c		\
		avlt/ft_avlt_left_rot.c		\
		avlt/ft_avlt_right_rot.c


OBJS	=	$(SRCS:.c=.o)

# COLORS
C_NO	=	"\033[00m"
C_OK	=	"\033[35m"
C_GOOD	=	"\033[32m"
C_ERROR	=	"\033[31m"
C_WARN	=	"\033[33m"

# DBG MESSAGE
SUCCESS	=	$(C_GOOD)SUCCESS$(C_NO)
OK		=	$(C_OK)OK$(C_NO)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $@ $^
	@ranlib $@
	@echo "Compiling & indexing" [ $(NAME) ] $(SUCCESS)

%.o: %.c
	@$(CC) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re