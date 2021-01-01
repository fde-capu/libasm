NAME		=	libasm
SRCS		=	ft_strlen.s
OBJS		=	$(SRCS:.s=.o)
NASM		=	nasm
NASMFLAGS	=	-f elf64
LD			=	ld
LDFLAGS		=
CC			=	clang
CCFLAGS		=	-Wall -Werror -Wextra
CCLINKS		=	-L -lasm
CCSRCS		=	main.c

all:		$(NAME)
	$(CC) $(CCFLAGS) $(CCSRCS) $(CCLINKS) -o a.out

$(NAME):	$(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(NAME).a

$(OBJS):
	$(NASM) $(NASMFLAGS) $(SRCS)

clean:
	find . -name *.o -exec rm {} \; 

fclean:		clean
	rm -f $(NAME).a
	rm -f a.out

hello:		all
	helloworld/helloworld

re:			fclean all

t:			test
test:		re
	./$(NAME).a
	./a.out
