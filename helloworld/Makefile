NAME		=	helloworld
OBJS		=	$(NAME).o
NASM   		=	nasm
NASMFLAGS	=	-f elf64
LD	   		=	ld
LDFLAGS		=	

all:		$(NAME)

$(NAME):	$(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(NAME)

$(NAME).o:	$(NAME).s
	$(NASM) $(NASMFLAGS) $(NAME).s

clean:
	find . -name *.o -exec rm {} \; 

fclean:	clean
	rm -f $(NAME)

re:			fclean all

t:			test
test:		re
	./$(NAME)
