all: RandevuOps

RandevuOps: main.o randevuOps.o 
	gcc main.o randevuOps.o -o RandevuOps

main.o: main.c
	gcc -c main.c 

randevuOps.o: randevuOps.c randevuOps.h
	gcc -c randevuOps.c

run:
	RandevuOps.exe