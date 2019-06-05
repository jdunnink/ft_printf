# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lravier <marvin@codam.nl>                    +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/18 08:51:33 by lravier        #+#    #+#                 #
#    Updated: 2019/05/08 12:11:47 by lravier       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = test

SRC =	test_main.c		\
		float_test.c	\
		int_test.c		\
		uint_test.c		\

OBJ = $(SRC:.c=.o)
SRCDIR = srcs
OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

HEADER = -I includes/ -I libftprintf/includes/
cc = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = -L libftprintf/ -lftprintf

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(NAME): $(OBJS)
	make -C libftprintf/ 
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(HEADER) $(LIB)

$(OBJS): $(SRCS)
	/bin/mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAGS) $(SRCS) $(HEADER)
	/bin/mv $(OBJ) $(OBJDIR)/

clean:
	/bin/rm -Rf $(OBJDIR)
	/bin/rm -Rf *~ *#
	make -C libftprintf/ clean

fclean: clean
	make -C libftprintf/ fclean
	/bin/rm -f $(NAME)

re: fclean all
