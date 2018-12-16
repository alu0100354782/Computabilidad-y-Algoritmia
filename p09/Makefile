CC = g++
CXXFLAGS = -g -Wfatal-errors -std=c++11
SRC = src/
BIN = bin/p09.out
DOX = Doxyfile

OBJS = $(SRC)Alphabet.o $(SRC)Transition.o $(SRC)State.o $(SRC)Dfa.o $(SRC)Main.o $(SRC)Production.o $(SRC)Rule.o $(SRC)Grammar.o

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
