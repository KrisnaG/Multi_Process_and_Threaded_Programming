# makefile for nordvik
# author: Krisna Gusti (kgusti@myune.edu.au)

COMPILER = gcc
CFLAGS = -Wall -pedantic -g
COBJS = nordvik_util.o
CEXES = nordvik
PROGRAM = nordvik 

all: clean ${CEXES} run

nordvik: nordvik.c ${COBJS}
	${COMPILER} ${CFLAGS} nordvik.c ${COBJS} -pthread -o nordvik 

%.o: %.c %.h  makefile
	${COMPILER} ${CFLAGS} $< -c -pthread

build: clean ${CEXES}

clean:
	rm -f *.o *~ ${CEXES}

run:
	./${PROGRAM}