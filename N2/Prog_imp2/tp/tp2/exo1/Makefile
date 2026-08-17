all: main.o matrice.o
	gcc -o main main.o matrice.o

matrice.o: matrice.c matrice.h
	gcc -c matrice.c

main.o: main.c matrice.h
	gcc -c main.c

clean:
	rm -f *.o main
