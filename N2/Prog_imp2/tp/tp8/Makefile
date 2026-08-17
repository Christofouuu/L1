all: main.o liste.o poste.o
	gcc -o main main.o liste.o

liste.o: liste.c liste.h
	gcc -c liste.c

poste.o: poste.c poste.h
	gcc -c poste.c

main.o: main.c liste.h poste.h
	gcc -c main.c

clear: 
	rm -f *.o main
