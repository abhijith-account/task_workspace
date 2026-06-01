CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++20

all: calc

calc: main.o calculator.o shape.o
	$(CXX) $(CXXFLAGS) -o calc main.o calculator.o shape.o

main: main.cpp calculator.h shape.h
	$(CXX) $(CXXFLAGS) -c main.cpp

calculator: calculator.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c calculator.cpp

shape: shape.h calculator.h shape.cpp
	$(CXX) $(CXXFLAGS) -c shape.cpp

clean:
	rm -f calc *.o






