test: test_minqueue_example.o
	g++ -o test test_minqueue_example.o
	
test_minqueue_example.o: test_minqueue_example.cpp MinQueue.h MinQueue.cpp
	g++ -c test_minqueue_example.cpp