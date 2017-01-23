#
#enigma: obj/enigma.o
#	gcc "src/enigma.c" -o "obj/enigma.o" -c

#CC=gcc
#CFLAGS=-c -Wall -std=c99
#LDFLAGS=
#SOURCES=src/enigma.c
#OBJECTS=obj/../$(SOURCES:.c=.o)
#EXECUTABLE=enigma

#all: $(SOURCES) $(EXECUTABLE)

#$(EXECUTABLE): $(OBJECTS)
#	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

#.c.o:
#	$(CC) $(CFLAGS) $< -o $@


SOURCEDIR = src
BUILDDIR = build
EXECUTABLE = bin/enigma

CCOMPILER = gcc
CFLAGS_OBJ = -Wall -std=c99 -c
CFLAGS_EXEC = -Wall -std=c99 -no-pie
LDFLAGS =
#INC = -Iinc


_OBJS = enigma.o \
        wheels.o

OBJS = $(patsubst %,$(BUILDDIR)/%,$(_OBJS))

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c
	$(CCOMPILER) $< -o $@  $(CFLAGS_OBJ)

$(EXECUTABLE): $(OBJS)
	$(CCOMPILER) $^ -o $@ $(CFLAGS_EXEC)

#.PHONY: clean

#clean:
#	rm -f $(BUILDDIR)/*.o $(EXECUTABLE)
