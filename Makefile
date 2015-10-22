#Makefile

main: main.o List.o DoubleList.o Stack.o RPN.o Queue.o
	gcc main.o List.o DoubleList.o Stack.o RPN.o Queue.o -o main

main.o: main.c List.h DoubleList.h Stack.h RPN.h Queue.h
	gcc -c main.c

List.o: List.c List.h
	gcc -c List.c

DoubleList.o: DoubleList.c DoubleList.h
	gcc -c DoubleList.c

Stack.o: Stack.c Stack.h
	gcc -c Stack.c

RPN.o: RPN.c RPN.h
	gcc -c RPN.c

Queue.o: Queue.c Queue.h
	gcc -c Queue.c


clean:
	rm -rf *.o
