CFLAGS=-Wall -ansi -pedantic -lMLV -g
EXEC=Labyrinthe
SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
CC=gcc

all: $(EXEC)

Labyrinthe: Main.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

Main.o: Main.c include/Generation.h include/Utilisation.h
	$(CC) -c $< $(CFLAGS)

Utilisation.o: src/Utilisation.c include/Utilisation.h
	$(CC) -c $< $(CFLAGS)

Generation.o: src/Generation.c include/Generation.h include/Affichage.h
	$(CC) -c $< $(CFLAGS)

Affichage.o: src/Affichage.c include/Affichage.h include/Labyrinthe.h
	$(CC) -c $< $(CFLAGS)

Labyrinthe.o: src/Labyrinthe.c include/Labyrinthe.h include/Unionfind.h include/File.h
	$(CC) -c $< $(CFLAGS)
	
Unionfind.o: src/Unionfind.c include/Unionfind.h include/Tableau.h
	$(CC) -c $< $(CFLAGS)

FileAttente.o: src/FileAttente.c include/FileAttente.h include/Tableau.h
	$(CC) -c $< $(CFLAGS)
	
Tableau.o: src/Tableau.c include/Tableau.h
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf *.o
	cd src; \
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
