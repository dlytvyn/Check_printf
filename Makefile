#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/09 15:36:43 by dlytvyn           #+#    #+#              #
#    Updated: 2018/02/09 15:36:44 by dlytvyn          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iincludes

FT_PRINTF = ./ft_printf/ft_printf.c\
		./ft_printf/ft_al.c\
        ./ft_printf/type_of_data.c\
        ./ft_printf/parse.c\
        ./ft_printf/ft_puttext.c\
        ./ft_printf/ft_char_type.c\
		./ft_printf/print_cs.c\
        ./ft_printf/ft_atoi_n.c\
        ./ft_printf/ft_realloc.c\
        ./ft_printf/ft_newlist.c\
        ./ft_printf/ft_clear.c\
        ./ft_printf/ft_pointer.c\
        ./ft_printf/ft_len.c\
        ./ft_printf/search_base.c\
		./ft_printf/colors.c\
        ./ft_printf/ft_itoa_base.c\
		./ft_printf/ft_realloc_cat.c\
		./ft_printf/get_format.c\
        ./ft_printf/new_format.c\
        ./ft_printf/unicode.c\
        ./ft_printf/ft_itoa_base_sign.c\
        ./ft_printf/get_format_2.c\
        ./ft_printf/unicode_write.c\
        ./ft_printf/unicode_len.c\
        ./ft_printf/ft_typing.c\
        ./ft_printf/if_not_minus.c\

LIBFT = ./libft/ft_memset.c\
		./libft/ft_bzero.c\
 		./libft/ft_memcpy.c\
 		./libft/ft_memccpy.c\
 		./libft/ft_memmove.c\
 		./libft/ft_memchr.c\
 		./libft/ft_memcmp.c\
 		./libft/ft_strlen.c\
 		./libft/ft_strdup.c\
 		./libft/ft_strcpy.c\
 		./libft/ft_strncpy.c\
 		./libft/ft_strcat.c\
 		./libft/ft_strncat.c\
 		./libft/ft_strlcat.c\
 		./libft/ft_strchr.c\
 		./libft/ft_strrchr.c\
 		./libft/ft_strstr.c\
 		./libft/ft_strnstr.c\
 		./libft/ft_strcmp.c\
 		./libft/ft_strncmp.c\
 		./libft/ft_atoi.c\
 		./libft/ft_isalpha.c\
 		./libft/ft_isdigit.c\
 		./libft/ft_isalnum.c\
 		./libft/ft_isascii.c\
 		./libft/ft_isprint.c\
 		./libft/ft_toupper.c\
 		./libft/ft_tolower.c\
 		./libft/ft_memalloc.c\
 		./libft/ft_memdel.c\
 		./libft/ft_strnew.c\
 		./libft/ft_strdel.c\
 		./libft/ft_strclr.c\
 		./libft/ft_striter.c\
 		./libft/ft_striteri.c\
 		./libft/ft_strmap.c\
 		./libft/ft_strmapi.c\
 		./libft/ft_strequ.c\
 		./libft/ft_strnequ.c\
 		./libft/ft_strsub.c\
		./libft/ft_strjoin.c\
		./libft/ft_strtrim.c\
		./libft/ft_putchar.c\
		./libft/ft_putstr.c\
		./libft/ft_putnbr.c\
		./libft/ft_lstnew.c\
		./libft/ft_lstdelone.c\
		./libft/ft_lstdel.c\
		./libft/ft_lstadd.c\
		./libft/ft_lstiter.c\
		./libft/ft_lstmap.c\
		./libft/ft_itoa.c\

LIBFT_OBJ = $(LIBFT:.c=.o)

FT_PRINTF_OBJ = $(FT_PRINTF:.c=.o)

all: $(NAME)

$(NAME): $(FT_PRINTF_OBJ) $(LIBFT_OBJ)
	ar rc $(NAME) $(FT_PRINTF_OBJ) $(LIBFT_OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(FT_PRINTF_OBJ) $(LIBFT_OBJ)

fclean: clean
	cd libft && make fclean
	/bin/rm -f $(NAME)

re: fclean all