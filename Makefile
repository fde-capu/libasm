# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 14:42:49 by fde-capu          #+#    #+#              #
#    Updated: 2021/01/29 00:27:08 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a
PROOF_NAME	=	proof.out
ASMSRCS		=	hello.s ft_write.s
ASMOBJS		=	$(ASMSRCS:.s=.o)
NASM		=	nasm
NASMFLAGS	=	-f elf64
CC			=	clang
CCFLAGS		=	-Wall -Werror -Wextra -O0 -g
CCLINKS		=	$(NAME)
CCSRCS		=	main.c
CCHEADS		=	header.h
CCOBJS		=	$(CCSRCS:.c=.o)

all:		proof

$(NAME):	$(ASMOBJS)
	ar rcs $(NAME) $(ASMOBJS)

$(ASMOBJS):	%.o : %.s
	$(NASM) $(NASMFLAGS) $<

clean:
	rm -f $(ASMOBJS)
	rm -f $(CCOBJS)
#	find . -name '*.o' -exec rm {} \; 

fclean:		clean
	rm -f $(NAME)
	rm -f $(PROOF_NAME)

re:			fclean all

$(CCOBJS):	%.o : %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

proof:		$(NAME) $(CCOBJS) $(CCHEADS)
	$(CC) $(CCFLAGS) $(CCOBJS) -o $(PROOF_NAME) $(CCLINKS)

t:			test
test:		re proof
	./$(PROOF_NAME)
