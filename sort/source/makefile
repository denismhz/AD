IDIR = ../include
LDIR = ../lib
ODIR = obj
_DEPS = sort.h
_OBJ = main.o sort.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
CC = g++
CFLAGS = -L$(LDIR)
LIBS = -lsort
SRC = main.cpp sort.cpp

prog: main.cpp $(DEPS)
	$(CC) -o $@ $^ 

.PHONY: clean
	
clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
