all: trst

test: test_set.o
	g++ -std=c++11 -Wall -g -o test test_set.o

test_set.o: test_set.cpp set.cpp set.h
	g++ -std=c++11 -c -g -Wall test_set.cpp