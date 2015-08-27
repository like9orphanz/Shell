CFLAGS = -g -Wall 
CC = gcc

objects = myShell.o

test: $(objects)
	$(CC) -o myShell $(objects)

myShell.o: myShell.c parse.h

.PHONY : clean
clean: 
	rm myShell $(objects)
