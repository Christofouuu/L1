all: main.o flotte_voiture.o
	gcc -o main main.o flotte_voiture.o

flotte_voiture.o: flotte_voiture.c flotte_voiture.h
	gcc -c flotte_voiture.c

main.o: main.c flotte_voiture.h
	gcc -c main.c

clean: 
	rm -f *.o main