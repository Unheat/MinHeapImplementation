//========================================================
// CS 271
// Fall 2025
// minQueue.h
// This file contains the minQueue class declaration.  
// carefully.
//========================================================

#ifndef MINQUEUE_H
#define MINQUEUE_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

template <class T> 
class minQueue {
    public:
        minQueue();
        minQueue(T* A, int n);
        ~minQueue();
        minQueue(const minQueue<T>& other);
        minQueue<T>& operator=(const minQueue<T>& other);

        void insert(T x);
        T min() const; // Still need to do 
        T extractMin(); // Still need to do 
        void decreaseKey(int i, T k); // Still need to do
        void minHeapify(int i);
        void buildHeap(); 
        void sort(T* A); // Still need to do 

        void set(int i, T val); // Still need to do 
        void allocate(int n); // Still need to do
        std::string toString() const;
        void printHeap(); // Still need to do 

        void clear();
        int parent(int i) const;
        int left(int i) const;
        int right(int i) const;
        void swap (int indexA, indexB);

    private:
        int numberOfElements;
        int capacity;
        T* myArray;
        
        int parent(int i) const;
        int left(int i) const;
        int right(int i) const;
        void swap (int indexA, indexB);
};

#include "minQueue.cpp"

#endif
