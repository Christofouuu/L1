all: main.o polynome.o
	gcc -o main polynome.o main.o

polynome.o: polynome.c polynome.h
	gcc -c polynome.c

main.o: main.c polynome.h
	gcc -c main.c

clean: 
	rm -f *.c main
