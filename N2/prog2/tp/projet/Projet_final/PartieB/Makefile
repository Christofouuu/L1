all: main

grille.o: grille.c grille.h
	gcc -c -Wall grille.c

pion.o: pion.c pion.h grille.h
	gcc -c -Wall pion.c

main.o: main.c grille.c pion.c
	gcc -c -Wall main.c

main: main.o grille.o pion.o
	gcc -o main main.o grille.o pion.o  -lncurses

clean:
	rm -fr *.o main
