CC = g++
CXXFLAGS = -g -Wfatal-errors -std=c++11
SRC = src/
BIN = bin/p07.out
DOX = Doxyfile

OBJS = $(SRC)Alphabet.o $(SRC)Transition.o $(SRC)State.o $(SRC)Nfa.o $(SRC)Main.o


all:${OBJS}
	$(CC) $(CXXFLAGS) -o $(BIN) ${OBJS}


clean:
	rm -rf $(SRC)*.o $(BIN)

run:
	@./$(BIN)

doxy:
	doxygen $(DOX)

open_doc:
	firefox doc/html/index.html &
