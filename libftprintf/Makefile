#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jdunnink <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/20 09:33:47 by jdunnink      #+#    #+#                  #
#    Updated: 2019/05/28 18:40:21 by jdunnink      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

SRC =	ft_atoi.c			\
		ft_cinstr.c			\
		ft_count_cinstr.c	\
		ft_ctostr.c			\
		ft_itoa_base.c		\
		ft_utoa_base.c		\
		ft_ptoa.c			\
		ft_labs.c			\
		ft_memset.c			\
		ft_printf.c			\
		ft_stradd.c			\
		ft_strcat.c			\
		ft_strcpy.c			\
		ft_strdup_exep.c	\
		ft_strdup_until.c	\
		ft_strjoin.c		\
		ft_strlen.c			\
		ft_strdup.c			\
		ft_strndup.c		\
		ft_strnew.c			\
		ft_putchar.c		\
		ft_putstr.c			\
		pf_flag_override.c	\
		pf_get_specinfo.c	\
		pf_handle_csp.c		\
		pf_handle_idu.c		\
		pf_handle_x.c		\
		pf_handle_f.c		\
		pf_toa_sign.c		\
		pf_toa_unsign.c		\
		pf_dtoa.c			\
		pf_ltoa.c			\
		pf_add_pad.c		\

OBJ = $(SRC:.c=.o)

SRCDIR = srcs

OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

HEADER = -I includes

CC = gcc

NAME = libftprintf.a

CFLAGS = -c

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(OBJS): $(SRCS)
	/bin/mkdir -p $(OBJDIR) ;
	$(CC) $(CFLAGS) $(SRCS) $(HEADER) ;
	/bin/mv $(OBJ) $(OBJDIR)/

$(NAME): $(OBJS)
	ar rcs $@ $^
	ranlib $@

clean:
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all