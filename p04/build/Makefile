CC = g++ 
CXXFLAGS = -g -std=c++11
SRC = ../src/

OBJS = $(SRC)Bloque.o $(SRC)Fila.o $(SRC)Muro.o $(SRC)Main.o


all:${OBJS}
	$(CC) $(CXXFLAGS) -o p04 ${OBJS}
	

clean: 
	rm -rf $(SRC)*.o p04

run:
	@./p04