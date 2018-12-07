# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edinguim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 15:04:32 by edinguim          #+#    #+#              #
#    Updated: 2018/11/15 16:58:10 by edinguim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c\
	  ft_bzero.c\
	  ft_intsize.c\
	  ft_intmaxsize.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_islower.c\
	  ft_isprint.c\
	  ft_isspace.c\
	  ft_isupper.c\
	  ft_isnumber.c\
	  ft_itoa.c\
	  ft_ltoa.c\
	  ft_utoa_base.c\
	  ft_lstadd.c\
	  ft_lstappend.c\
	  ft_lstdel.c\
	  ft_lstdelone.c\
	  ft_lstiter.c\
	  ft_lstmap.c\
	  ft_lstnew.c\
	  ft_memalloc.c\
	  ft_memccpy.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memdel.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_putchar.c\
	  ft_putchar_fd.c\
	  ft_putendl.c\
	  ft_putendl_fd.c\
	  ft_putnbr.c\
	  ft_putnbr_fd.c\
	  ft_putstr.c\
	  ft_putstr_fd.c\
	  ft_puttab.c\
	  ft_strcat.c\
	  ft_strchr.c\
	  ft_strclen.c\
	  ft_strclr.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strdel.c\
	  ft_strdup.c\
	  ft_strequ.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strjoin.c\
	  ft_strlcat.c\
	  ft_strlen.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strncat.c\
	  ft_strncmp.c\
	  ft_strncpy.c\
	  ft_strnequ.c\
	  ft_strnew.c\
	  ft_strnstr.c\
	  ft_strrchr.c\
	  ft_strsplit.c\
	  ft_strstr.c\
	  ft_strsub.c\
	  ft_strtrim.c\
	  ft_strword.c\
	  ft_tabcat.c\
	  ft_tabccat.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  ft_joinfree.c\
	  ft_printf.c\
	  ft_printf_add_char.c\
	  ft_printf_add_conv.c\
	  ft_printf_buffer.c\
	  ft_printf_c.c\
	  ft_printf_conv.c\
	  ft_printf_di.c\
	  ft_printf_flags.c\
	  ft_printf_majc.c\
	  ft_printf_majd.c\
	  ft_printf_majo.c\
	  ft_printf_majs.c\
	  ft_printf_maju.c\
	  ft_printf_modulo.c\
	  ft_printf_oux.c\
	  ft_printf_p.c\
	  ft_printf_parse.c\
	  ft_printf_s.c\
	  ft_printf_unicode.c\
	  get_next_line.c\
	  ft_getopt.c\
	  ft_strsrch.c

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
