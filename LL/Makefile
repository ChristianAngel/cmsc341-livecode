all: main

main: LL.o main.cpp
	g++ LL.o main.cpp -o main

LL.o: LL.cpp LL.h Node.h
	g++ -c LL.cpp

run: main
	./main

val: main
	valgrind ./main

clean:
	rm -f *.o *~ \#*\# main
