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
        T min() const; // Still need to do 
        T extract_min(); // Still need to do 
        void decrease(int i, T k); // Still need to do
        void min_heapify(int i);
        void build_heap()(); 
        void sort(T* A); // Still need to do 

        void set(int i, T val); // Still need to do 
        void allocate(int n); // Still need to do
        std::string to_string() const;
        void printHeap(); // Still need to do 

        void clear();

    private:
        int numberOfElements;
        int capacity;
        T* myArray;

        int parent(int i) const;
        int left(int i) const;
        int right(int i) const;
        void swap(int indexA, int indexB);
};

#include "MinQueue.cpp"

#endif
