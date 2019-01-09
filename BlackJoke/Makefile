CC = g++
CFLAGS = -Werror
INCLUDES = .
LIBS =
BIN = bin
EXEC_NAME = $(BIN)/blackJoke

SRC = app_bash/main.cpp\
			lib_blackjoke/deck.cpp\
			lib_blackjoke/board.cpp

DEPS = lib_blackjoke/deck.h\
			lib_blackjoke/board.h

OBJ = $(patsubst %.cpp,$(BIN)/%.o,$(SRC))

$(EXEC_NAME) : $(OBJ)
	$(CC) -o $(EXEC_NAME) $(OBJ) $(LIBS)

$(BIN)/%.o: %.cpp $(DEPS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ -c $<

all : $(EXEC_NAME)

.PHONY: clean

clean :
	rm -rf $(BIN)
