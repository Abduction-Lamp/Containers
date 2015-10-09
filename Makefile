#Makefile

main: main.o List.o
	gcc main.o List.o -o main

main.o: main.c List.h
	gcc -c main.c

List.o: List.c List.h
	gcc -c List.c


clean:
	rm -rf *.o
