all: main.o matrice.o frequent.o
	gcc -o main main.o matrice.o frequent.o

matrice.o: matrice.h matrice.c
	gcc -c matrice.c

frequent.o: frequent.h frequent.c
	gcc -c frequent.c

main.o: main.c frequent.h matrice.h
	gcc -c main.c

clean: 
	rm -f *.o main 
