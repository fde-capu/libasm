all:
	cd helloworld && make test
clean:
	find . -name *.o -exec rm {} \; 
fclean:	clean
	find . -name *.out -exec rm {} \; 
hello:	all
	helloworld/helloworld
