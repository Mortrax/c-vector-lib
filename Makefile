CC=gcc-7
CFLAGS=-std=c11
LFLAGS=-lm
SRC=vector.c vector_test.c
OBJ=vector_test.out

vector_test.out: vector.c vector.h vector_test.c
	$(CC) $(CFLAGS) $(SRC) $(LFLAGS) -o $(OBJ)

clean:
	\rm *.out
