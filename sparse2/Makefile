all:sparse

sparse: main.o init.o lowert.o
	gcc main.o init.o lowert.o -o proj

main.o : main.c
	gcc -c main.c

init.o: init.c
	gcc -c init.c

lowert.o: lowert.c
	gcc -c lowert.c