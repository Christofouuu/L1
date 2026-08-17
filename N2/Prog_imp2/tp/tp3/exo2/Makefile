all: main_top14_etu.o Equipe.o Match.o
	gcc -o main main_top14_etu.o Equipe.o Match.o
Equipe.o:Equipe.c Equipe.h
	gcc -c Equipe.c 
Match.o: Match.c Match.h
	gcc -c Match.c
main_top14_etu.o: main_top14_etu.c Equipe.h Match.h
	gcc -c main_top14_etu.c
clean:
	rm -f *.o main