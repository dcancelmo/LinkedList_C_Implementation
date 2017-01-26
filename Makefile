#Daniel Cancelmo
#Makefile to create an executable of my program to create a linked list and test it
CC=gcc

listMake : main.c
	$(CC) -o listTest main.c
