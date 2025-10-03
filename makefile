test: minqueue_test.o
	g++ -o test minqueue_test.o
	
minqueue_test.o: minqueue_test.cpp MinQueue.h MinQueue.cpp
	g++ -c minqueue_test.cpp