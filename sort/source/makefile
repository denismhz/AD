IDIR = ../include
LDIR = ../lib
ODIR = obj
_DEPS = sort.h person.h
_OBJ = main.o sort.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
CC = g++
CFLAGS = -L$(LDIR)
LIBS = -lsort
SRC = main.cpp sort.cpp
.DEFAULT_GOAL := vis

prog: main.cpp $(DEPS)
	$(CC) -o $@ $^ 

vis: sortv.cpp button.h $(DEPS)
	$(CC) -o $@ $^ -lSDL2 -lSDL2_ttf

.PHONY: clean
	
clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

start:
	./prog
