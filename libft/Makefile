# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 13:14:22 by bmikaeli          #+#    #+#              #
#    Updated: 2014/02/20 13:37:59 by bmikaeli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS_D = srcs/
OBJS_D = objs/
HEADERS = includes/
SRCS = ft_putchar.c\
		ft_putstr.c\
		ft_putnbr.c\
		ft_putendl.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_strlen.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_strcpy.c\
		ft_strncpy.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_strdup.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strjoin.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_strtolow.c\
		ft_isprint.c\
		ft_isalnum.c\
		ft_isdigit.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_atoi.c\
		ft_itoa.c\
		ft_bzero.c\
		ft_memset.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstaddback.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstcount.c\
		ft_lstfree.c\
		ft_removeduplicates.c\
		get_next_line.c

OBJS = $(SRCS:.c=.o)
OBJS_P = $(addprefix $(OBJS_D), $(OBJS))

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS_P)
	@ar rc $(NAME) $(OBJS_P)
	@ranlib $(NAME)

$(addprefix $(OBJS_D), %.o): $(addprefix $(SRCS_D), %.c)
	@mkdir -p $(OBJS_D)
	@$(CC) -c -o $@ $^ $(CFLAGS) -I $(HEADERS)

clean:
	rm -f $(OBJS_P)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean, fclean, re, all
