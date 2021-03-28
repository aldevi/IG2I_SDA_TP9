c=gcc
op=-Wall -Wextra

all : es.o pile.o file.o permut.o echiquier.o tp9.c 	
	$(c) $(op)  es.o pile.o file.o permut.o echiquier.o tp9.c -o tp9.exe
pile.o : pile.c pile.h
	$(c) $(op) -c pile.c	
file.o : file.c file.h
	$(c) $(op) -c file.c	
es.o : es.c es.h
	$(c) $(op) -c es.c
permut.o : permut.c permut.h
	$(c) $(op) -c permut.c
echiquier.o : echiquier.c echiquier.h
	$(c) $(op) -c echiquier.c

clean :
	rm -rf *.o *.exe