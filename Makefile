CC=g++
CFLAGS=-c -std=c++17 -fopenmp
LDFLAGS=-std=c++17 -fopenmp

all: main

main: main_
	./main

test: main_
	./main

main_: main.o test.o qsort-omp.o
	$(CC) $(LDFLAGS) main.o test.o qsort-omp.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp -o test.o

qsort-omp.o: qsort-omp.cpp
	$(CC) $(CFLAGS) qsort-omp.cpp -o qsort-omp.o

clean:
	rm -f main test *.o