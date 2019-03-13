all: driver

driver: driver.cpp BST.o Node.o
	g++ -Wall driver.cpp Node.o BST.o -o driver

Node.o: Node.cpp Node.h
	g++ -Wall -c Node.cpp

BST.o: BST.cpp BST.h
	g++ -Wall -c BST.cpp

run: driver
	./driver

val: driver
	valgrind ./driver
