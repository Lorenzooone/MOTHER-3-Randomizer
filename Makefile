CXX=clang++
CXXFLAGS=-g -std=c++11 -Wall -pedantic
BIN=M3Randomizer

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) -o $(BIN) $^

%.o: %.c
	$(CXX) $@ -c $<

clean:
	- rm -f *.o;
	- rm -f $(BIN)
