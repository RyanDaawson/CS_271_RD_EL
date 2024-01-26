driver: Test_set.o
	g++ -o driver Test_set.o
	
listdriver.o: Test_set.cpp set.h set.cpp
	g++ -c Test_set.cpp