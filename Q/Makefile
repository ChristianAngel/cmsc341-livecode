all: main

main: Queue.o main.cpp
	g++ Queue.o main.cpp -o main

Queue.o: Queue.cpp Queue.h Node.h
	g++ -c Queue.cpp

run: main
	./main

val: main
	valgrind ./main

clean:
	rm -f *.o *~ \#*\# main
