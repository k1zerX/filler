# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbatz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/25 21:10:51 by kbatz             #+#    #+#              #
#    Updated: 2019/10/25 23:30:34 by kbatz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	kbatz.filler
LIB		=	libft

# **************************************************************************** #

SRCDIR	=	src/
OBJDIR	=	.obj/
HDRDIR	=	include/
TESTDIR	=	test/

# **************************************************************************** #

LIBDIR	=	$(addsuffix /,$(LIB))
SRC		=	ft_read.c		\
			heat_map.c		\
			hm_queue.c		\
			main.c			\
			read_tools.c	\
			tools.c
OBJ		=	$(SRC:%.c=%.o)
HDR		=	$(wildcard $(HDRDIR)*.h)
TEST	=	$(patsubst $(TESTDIR)%,%,$(wildcard $(TESTDIR)*))
LFLAG	=	$(addprefix -L,$(LIBDIR)) $(addprefix -,$(patsubst lib%,l%,$(LIB)))
IFLAG	=	$(addprefix -I,$(HDRDIR)) $(addprefix -I,$(LIBDIR))
CFLAG	=	-Wall -Wextra -Werror
CC		=	gcc

# **************************************************************************** #

vpath %.c $(SRCDIR)
vpath %.o $(OBJDIR)

# **************************************************************************** #

all: lib.all $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	$(CC) $(addprefix $(OBJDIR), $(OBJ)) -o $(NAME) $(IFLAG) $(LFLAG)

$(OBJ): %.o: %.c $(HDR)
	$(CC) $(CFLAG) $(IFLAG) -c $< -o $(OBJDIR)$@

$(OBJDIR):
	mkdir $(OBJDIR)

clean: lib.fclean
	rm -Rf $(OBJDIR)

fclean: clean
	rm -Rf $(NAME)

re: fclean all

lib%:
	$(foreach C,$(LIBDIR),\
		make -C $(C) $(patsubst lib.%,%,$@) \
	)

norm:
	norminette $(addprefix $(SRCDIR),$(SRC))
	norminette $(HDR)

g: $(OBJDIR) $(OBJ)
	$(CC) -g $(addprefix $(SRCDIR),$(SRC)) -o debug_$(NAME) $(IFLAG) $(LFLAG)

gclean:
	rm -Rf debug_$(NAME)
	rm -Rf debug_$(NAME).dSYM

t: all $(TEST)

$(TEST): %:
	@echo "--------------------------------------------------"
	@echo "| >>>>> TEST \""$@"\" START >>>>> |"
	@echo ""
	@./$(NAME) $(TESTDIR)$@
	@echo ""
	@echo "| <<<<< TEST \""$@"\" END <<<<< |"
	@echo "--------------------------------------------------"
