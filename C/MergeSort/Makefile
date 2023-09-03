CC=gcc
FLAGS= -c -Wall

all: MergeSort

MergeSort: main.o MergeSort.o
	$(CC) main.o MergeSort.o -o MergeSort

main.o:
	$(CC) $(FLAGS) main.c

MergeSort.o:
	$(CC) $(FLAGS) MergeSort.c MergeSort.h

clean :
	rm -rf *.o *.gch MergeSort
