# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 14:42:49 by fde-capu          #+#    #+#              #
#    Updated: 2021/01/28 16:05:40 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a
PROOF_NAME	=	proof.out
ASMSRCS		=	ft_strlen.s
ASMOBJS		=	$(ASMSRCS:.s=.o)
NASM		=	nasm
NASMFLAGS	=	-f elf64
CC			=	clang
CCFLAGS		=	-Wall -Werror -Wextra -O3
CCLINKS		=	-L -lasm
CCSRCS		=	main.c
CCHEADS		=	header.h
CCOBJS		=	$(CCSRCS:.c=.o)

all:		proof

$(NAME):	$(ASMOBJS)
	ar rc $(NAME) $(ASMOBJS)

$(ASMOBJS):	$(ASMSRCS)
	$(NASM) $(NASMFLAGS) $(ASMSRCS)

clean:
	find . -name '*.o' -exec rm {} \; 
	find . -name '*.gch' -exec rm {} \; 

fclean:		clean
	rm -f $(NAME).a
	rm -f a.out

re:			fclean all

$(CCOBJS):	$(CCSRCS)
	$(CC) $(CCFLAGS) -o $(CCOBJS) -c $(CCSRCS)

proof:		$(NAME) $(CCOBJS) $(CCHEADS)
	$(CC) $(CCFLAGS) -o $(PROOF_NAME) $(CCOBJS) $(CCLINKS)

t:			test
test:		re proof
	./$(PROOF_NAME)
