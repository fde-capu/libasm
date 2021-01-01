NAME		=	helloworld
OBJS		=	$(NAME).o
NASM   		=	nasm
NASMFLAGS	=	-f elf64
LD	   		=	ld
LDFLAGS		=	
VALGRIND	=	valgrind --leak-check=yes

all:		$(NAME)

$(NAME):	$(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(NAME)

$(NAME).o:	$(NAME).asm
	$(NASM) $(NASMFLAGS) $(NAME).asm

clean:
	find . -name *.o -exec rm {} \; 

fclean:	clean
	rm -f $(NAME)

re:			fclean all

t:			test
test:		re
	./$(NAME)

v:			valgrind
val:		valgrind
valgrind:	re
	$(VALGRIND) ./$(NAME)
