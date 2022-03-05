

IDIR = ./include
CC = gcc
CFLAGS = -I$(IDIR)


LDIR = lib
ODIR = obj
SDIR = src

LIBS=-lm


_OBJ = main.o knapsak.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

_DEPS = knapsak.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


clean:
	del main.exe
	del obj\*.o