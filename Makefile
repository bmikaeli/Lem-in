# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/13 12:07:57 by bmikaeli          #+#    #+#              #
#    Updated: 2014/02/19 15:25:25 by bmikaeli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Werror -Wextra
SRCS_D = srcs/
OBJS_D = objs/
HEADERS = includes/
SRCS = main.c search.c rooms.c tubes.c ant.c

OBJS = $(SRCS:.c=.o)
OBJS_P = $(addprefix $(OBJS_D), $(OBJS))
LDIR = libft
LFLAGS = -L$(LDIR) -lft

NAME = lem_in

all: lib $(NAME)

$(NAME): $(LDIR)/libft.a $(OBJS_P)
	$(CC) -o $(NAME) $(OBJS_P) $(CFLAGS) $(LFLAGS)

$(addprefix $(OBJS_D), %.o): $(addprefix $(SRCS_D), %.c)
	@mkdir -p $(OBJS_D)
	$(CC) -c -o $@ $^ $(CFLAGS) -I $(HEADERS) -I $(LDIR)/includes

lib:
	make -C $(LDIR)

clean:
	rm -f $(OBJS_P)
	make clean -C $(LDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LDIR)

re: fclean all

.PHONY: clean, fclean, re, all
