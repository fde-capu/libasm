# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 14:42:49 by fde-capu          #+#    #+#              #
#    Updated: 2021/02/08 09:08:55 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a
PROOF_NAME	=	proof.out
ASMSRCS		=	hello.s ft_write.s ft_strlen.s ft_strcpy.s ft_strcmp.s \
				ft_read.s ft_strdup.s
ASMOBJS		=	$(ASMSRCS:.s=.o)
NASM		=	nasm
NASMFLAGS	=	-f elf64
CC			=	clang
CCFLAGS		=	-Wall -Werror -Wextra -O0 -g
CCLINKS		=	$(NAME)
CCSRCS		=	main.c tests.c tests2.c tests3.c tests4.c helpers.c
CCHEADS		=	header.h
CCOBJS		=	$(CCSRCS:.c=.o)
VALGRIND	=	valgrind --leak-check=full
ALLLEAKS	=	--show-leak-kinds=all
all:		proof

library:	$(NAME)

$(NAME):	$(ASMOBJS)
	ar rcs $(NAME) $(ASMOBJS)

$(ASMOBJS):	%.o : %.s
	$(NASM) $(NASMFLAGS) $<

clean:
	rm -f $(ASMOBJS)
	rm -f $(CCOBJS)

fclean:		clean
	rm -f $(NAME)
	rm -f $(PROOF_NAME)

re:			fclean all

$(CCOBJS):	%.o : %.c $(CCHEADS)
	$(CC) $(CCFLAGS) -o $@ -c $<

v:			proof
	$(VALGRIND) $(ALLLEAKS) ./$(PROOF_NAME)

proof:		$(NAME) $(CCOBJS)
	$(CC) $(CCFLAGS) $(CCOBJS) -o $(PROOF_NAME) $(CCLINKS)

t:			test
test:		re proof
	./$(PROOF_NAME)
