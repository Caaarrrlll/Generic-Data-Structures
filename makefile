main: main.cpp
	g++ -std=c++11 -Wall -Werror=pedantic main.cpp -o main.o

run:
	./main.o

clean:
	rm *.o