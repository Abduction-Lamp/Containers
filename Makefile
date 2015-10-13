#Makefile

main: main.o List.o DoubleList.o
	gcc main.o List.o DoubleList.o -o main

main.o: main.c List.h DoubleList.h
	gcc -c main.c

List.o: List.c List.h
	gcc -c List.c

DoubleList.o: DoubleList.c DoubleList.h
	gcc -c DoubleList.c


clean:
	rm -rf *.o
