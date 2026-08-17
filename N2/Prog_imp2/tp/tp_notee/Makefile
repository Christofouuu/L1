all: main.o carnet.o 
	gcc -o main main.o carnet.o

carnet.o: carnet.c Carnet.h
	gcc -c carnet.c

main.o: main.c Carnet.h
	gcc -c main.c

clean: 
	rm -f *.o main