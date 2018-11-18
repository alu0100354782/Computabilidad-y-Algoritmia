CC = g++ 
CXXFLAGS = -g -Wfatal-errors -std=c++11
SRC = ../src/

OBJS = $(SRC)Bloque.o $(SRC)Fila.o $(SRC)Muro.o $(SRC)Main.o


all:${OBJS}
	$(CC) $(CXXFLAGS) -o p04.out ${OBJS}
	

clean: 
	rm -rf $(SRC)*.o p04.out

run:
	@./p04.out