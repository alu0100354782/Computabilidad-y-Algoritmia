CC = g++ 
CXXFLAGS = -g -Wfatal-errors -std=c++17
SRC = src/
BUILD = build/

OBJS = $(SRC)Menu.o $(SRC)Alfabeto.o $(SRC)Lenguaje.o $(SRC)Main.o


all:${OBJS}
	$(CC) $(CXXFLAGS) -o $(BUILD)p05.out ${OBJS}
	

clean: 
	rm -rf $(SRC)*.o $(BUILD)p05.out

run:
	@$(BUILD)p05.out
