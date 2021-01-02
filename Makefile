NAME		=	libasm
SRCS		=	ft_strlen.s
OBJS		=	$(SRCS:.s=.o)
NASM		=	nasm
NASMFLAGS	=	-f elf64
LD			=	ld
LDFLAGS		=
CC			=	clang
CCFLAGS		=	-Wall -Werror -Wextra -v
CCLINKS		=	-L -lasm
CCSRCS		=	main.c

all:		$(NAME)
	$(CC) $(CCFLAGS) $(CCLINKS) $(CCSRCS) -o a.out

$(NAME):	$(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(NAME).a

$(OBJS):
	$(NASM) $(NASMFLAGS) $(SRCS)

clean:
	find . -name *.o -exec rm {} \; 

fclean:		clean
	rm -f $(NAME).a
	rm -f a.out

re:			fclean all

t:			test
test:		re
	./$(NAME).a
	./a.out
