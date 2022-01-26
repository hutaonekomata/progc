all:	a.out
tree.o:	tree.c tree.h
	cc -c tree.c
prog33-02.o:	prog33-02.c tree.c
	cc -c prog33-02.c
prog33-03.o:	prog33-03.c tree.c
	cc -c prog33-03.c
prog33-04.o:	prog33-04.c tree.c
	cc -c prog33-04.c
prog33-02:	prog33-02.o tree.o
	cc -o prog33-02 prog33-02.o tree.o
prog33-03:	prog33-03.o tree.o
	cc -o prog33-03 prog33-03.o tree.o
prog33-04:	prog33-04.o tree.o
	cc -o prog33-04 prog33-04.o tree.o
clean:
	rm *.o
