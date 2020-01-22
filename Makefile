# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/21 21:58:57 by rjeraldi          #+#    #+#              #
#    Updated: 2020/01/22 20:12:12 by rjeraldi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
DEPS = *.h
DEPSDIR = includes
SRC = main.c\
	  draw.c\
	  read_file.c\
	  free.c
SRCDIR = srcs
OBJ = $(SRC:.c=.o)
CC = /usr/bin/gcc
CCFLAGS = -Wall -Wextra -Werror
RM = /bin/rm
RMFLAGS = -f
LIBFT = ft
LIBFTDIR = $(SRCDIR)/libft
LIBX = mlx
LIBXDIR = $(SRCDIR)/minilibx_macos
FRAMEWORKS = -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(LIBFT) $(LIBX) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(FRAMEWORKS) -I $(DEPSDIR) -I $(LIBFTDIR) -I $(LIBXDIR) -L $(LIBFTDIR) -l$(LIBFT) -L $(LIBXDIR) -l$(LIBX) -o $(NAME) $^

$(LIBFT):
	make -C $(LIBFTDIR)

$(LIBX):
	make -C $(LIBXDIR)

$(OBJ): %.o : $(SRCDIR)/%.c $(DEPSDIR)/$(DEPS)
	$(CC) $(CCFLAGS) -I $(DEPSDIR) -I $(LIBFTDIR) -I $(LIBXDIR) -c -o $@ $<

$(SRCDIR)/$(SRC):

$(DEPSDIR)/$(DEPS):

clean:
	make -C $(LIBFTDIR) clean
	make -C $(LIBXDIR) clean
	$(RM) $(RMFLAGS) $(OBJ)

fclean: clean
	make -C $(LIBFTDIR) fclean
	make -C $(LIBXDIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all
