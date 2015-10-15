#Makefile

main: main.o List.o DoubleList.o Stack.o
	gcc main.o List.o DoubleList.o Stack.o -o main

main.o: main.c List.h DoubleList.h Stack.h
	gcc -c main.c

List.o: List.c List.h
	gcc -c List.c

DoubleList.o: DoubleList.c DoubleList.h
	gcc -c DoubleList.c

Stack.o: Stack.c Stack.h
	gcc -c Stack.c


clean:
	rm -rf *.o
