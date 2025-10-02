//========================================================
// CS 271
// Fall 2025
// MinQueue.h
// This file contains the MinQueue class declaration.  
// carefully.
//========================================================

#ifndef MinQueue_H
#define MinQueue_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

template <class T> 
class MinQueue{
    public:
        MinQueue();
        MinQueue(T* A, int n);
        ~MinQueue();
        MinQueue(const MinQueue<T>& other);
        MinQueue<T>& operator=(const MinQueue<T>& other);

        void insert(T x);
        T min() const; 
        T extract_min(); 
        void decrease_key(int i, T k); 
        void min_heapify(int i);
        void build_heap(); 
        void sort(T* A); // Still need to do 

        void set(int i, T val); 
        void allocate(int n); 
        std::string to_string() const;
        void printHeap() const; 

        void clear();

    private:
        int numberOfElements;
        int capacity;
        T* myArray;

        int parent(int i) const;
        int left(int i) const;
        int right(int i) const;
        void swapIndex(int indexA, int indexB);
};

#include "MinQueue.cpp"

#endif
