CC=gcc
CFLAGS=-g -Wall -Iinclude -DDEBON
LIBS=
SRC=src/*.c
OUTFILE=bin/tte.out

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUTFILE) $(LIBS)