# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/05 23:41:00 by hhow-cho          #+#    #+#              #
#    Updated: 2019/06/06 00:23:48 by hhow-cho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc $(FLAGS) -I libft
FLAGS	=	-Wall -Wextra -Werror
NAME	=	libft.a
SRCS	=	ft_memset.c					\
			ft_bzero.c					\
			ft_memcpy.c					\
			ft_memccpy.c				\
			ft_memmove.c				\
			ft_memchr.c					\
			ft_memcmp.c					\
			ft_strlen.c					\
			ft_strdup.c					\
			ft_strcpy.c					\
			ft_strncpy.c				\
			ft_strcat.c					\
			ft_strcat_r.c				\
			ft_strncat.c				\
			ft_strlcat.c				\
			ft_strchr.c					\
			ft_strrchr.c				\
			ft_strstr.c					\
			ft_strnstr.c				\
			ft_strcmp.c					\
			ft_strncmp.c				\
			ft_atoi.c					\
			ft_isalpha.c				\
			ft_isdigit.c				\
			ft_isalnum.c				\
			ft_isascii.c				\
			ft_isprint.c				\
			ft_toupper.c				\
			ft_tolower.c				\
			ft_memalloc.c				\
			ft_memdel.c					\
			ft_strnew.c					\
			ft_strdel.c					\
			ft_strclr.c					\
			ft_striter.c				\
			ft_striteri.c				\
			ft_strmap.c					\
			ft_strmapi.c				\
			ft_strequ.c					\
			ft_strnequ.c				\
			ft_strsub.c					\
			ft_strjoin.c				\
			ft_strtrim.c				\
			ft_strsplit.c				\
			ft_itoa.c					\
			ft_putchar.c				\
			ft_putchar_fd.c				\
			ft_putstr.c					\
			ft_putstr_fd.c				\
			ft_putendl.c				\
			ft_putendl_fd.c				\
			ft_putnbr.c					\
			ft_putnbr_fd.c				\
			ft_lstnew.c					\
			ft_lstdelone.c				\
			ft_lstdel.c					\
			ft_lstadd.c					\
			ft_lstiter.c				\
			ft_lstmap.c					\
			ft_lstpush.c				\
			ft_lstfree.c				\
			ft_lstpop.c					\
			ft_lstpeek.c				\
			ft_lstpush.c				\
			ft_lstlen.c					\
			ft_bigint_add.c				\
			ft_bigint_divide_by_two.c	\
			ft_bigint_get_index.c		\
			ft_bigint_multiply_by_two.c	\
			ft_bigint_round.c			\
			ft_bigint_shift_right.c		\
			ft_bigint_trim.c			\
			ft_convert_base.c			\
			ft_str_insert.c				\
			ft_str_left_shift.c			\
			ft_str_right_shift.c			\
			ft_ulltoa.c					\

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