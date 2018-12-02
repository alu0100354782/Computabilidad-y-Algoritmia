CC = g++
CXXFLAGS = -g -Wfatal-errors -std=c++11
SRC = src/
BIN = bin/

OBJS = $(SRC)Transition.o $(SRC)State.o $(SRC)Dfa.o $(SRC)Main.o


all:${OBJS}
	$(CC) $(CXXFLAGS) -o $(BIN)p06.out ${OBJS}


clean:
	rm -rf $(SRC)*.o $(BIN)p06.out

run:
	@./$(BIN)p06.out

doxy:
	doxygen Doxyfile
