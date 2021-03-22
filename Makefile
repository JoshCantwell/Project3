#the compiler: gcc for c program, define as g++ for c++
CC = g++

# compiler flags:
# 	-g adds debugging informatino to the executable file
# 	-wall turns on most, but not all, compiler warnings
CXXFLAGS= -std=c++11 -g -Wall

OBJECTS = main.o Permutations.o	
HEADERS := $(shell find . -path ./test -prune -o -name "*.h" -print)

main: main.o $(OBJECTS)
		$(CC) $(CXXFLAGS) -o $@ $^

$(OBJECTS): $(HEADERS)

clean:
	$(RM) *.o *.gch core main test/TestCase
