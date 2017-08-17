# Staunton Sample
# sbsample
# pa4
# cmps101

CC = gcc
CFLAGS = -g -Wall -Werror -std=c99
OBJECTS = Graph.o FindComponents.o List.o

.PHONY: all
all: FindComponents
FindComponents	:	$(OBJECTS)
	$(CC) $(OBJECTS) -o FindComponents

FindComponents.o :	FindComponents.c
	$(CC) $(CFLAGS) -c FindComponents.c

List.o : List.c
	$(CC) $(CFLAGS) -c List.c

Graph.o : Graph.c
	$(CC) $(CFLAGS) -c Graph.c



.PHONY: clean
clean:
	rm $(OBJECTS) FindComponents


