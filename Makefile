#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lravier <marvin@codam.nl>                    +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/18 08:51:33 by lravier       #+#    #+#                  #
#    Updated: 2019/04/25 18:58:13 by jdunnink      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC =	create_field.c			\
		ft_error.c				\
		itocoor.c   			\
		lst_diff_order.c		\
		main.c					\
		print_field.c			\
		read_input.c			\
		read_tetromino.c		\
		set_indexes.c			\
		solve_pos.c				\
		solver.c				\
		tetro_translate.c 		\
		toggle_bits.c			\
		validate_tetro.c 		\

OBJ = $(SRC:.c=.o)
SRCDIR = srcs
OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

HEADER = -I includes/ -I libft/includes/
cc = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = -L libft/ -lft

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/ fclean && make -C libft
	$(CC) -o fillit $(CFLAGS) $(OBJS) $(HEADER) $(LIB)

$(OBJS): $(SRCS)
	/bin/mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAGS) $(SRCS) $(HEADER)
	/bin/mv $(OBJ) $(OBJDIR)/

clean:
	/bin/rm -Rf $(OBJDIR)
	/bin/rm -Rf *~ *#
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all