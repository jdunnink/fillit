#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lravier <marvin@codam.nl>                    +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/18 08:51:33 by lravier       #+#    #+#                  #
#    Updated: 2019/04/18 10:34:18 by lravier       ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = fillit
LIB = -L libft/ -lft
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RAWFILES = 
CSRCS = $(addsuffix .c, $(RAWFILES))
OSRCS = $(addsuffix .o, $(RAWFILES))
HEADER = fillit.h

all: $(NAME)

$(NAME): $(OSRCS)
	make -C libft/
	$(CC) $(CFLAGS) -c $(CSRCS) $(HEADER)
	$(CC) -o fillit $(OSRCS) $(HEADER) $(LIB)

$(LIB): $(LIBOS)
	@$(CC) $(CFLAGS) -c $(LIBCS) $(LIBHEAD)
	@ar rcs $(LIB) $(LIBOS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<