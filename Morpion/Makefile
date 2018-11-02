CC = g++
CFLAGS = -Werror
INCLUDES = .
LIBS =
BIN = bin
EXEC_NAME = $(BIN)/morpion_bash

SRC = app_bash/main.cpp\
			lib_gui/gui_bash.cpp\
			lib_morpion/morpion.cpp\
			lib_morpion/morpion_rond.cpp

DEPS = lib_morpion/morpion.h\
			 lib_morpion/morpion_rond.h\
			 lib_gui/gui_interface.h\
			 lib_gui/gui_bash.h

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
