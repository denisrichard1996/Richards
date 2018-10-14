CC = g++
CFLAGS = -Werror
EXEC_NAME = morpion_bash
INCLUDES = .
LIBS =
BIN = bin

SRC = app_bash/main.cpp\
			lib_morpion/morpion.cpp

DEPS = lib_morpion/morpion.h

OBJ = $(patsubst %.cpp,$(BIN)/%.o,$(SRC))

$(EXEC_NAME) : $(OBJ)
	$(CC) -o $(BIN)/$(EXEC_NAME) $(OBJ) $(LIBS)

$(BIN)/%.o: %.cpp $(DEPS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ -c $<

all : $(EXEC_NAME)

.PHONY: clean

clean :
	rm -rf $(BIN)
