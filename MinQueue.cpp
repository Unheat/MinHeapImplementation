#include "MinQueue.h"
#include <cassert>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>
using namespace std;

template <class T>
MinQueue<T>::MinQueue() {
    /*
    This is the original contrstuctor
    for my MinQueue. This will be an empty min Queue 
    heap with zero elements
    */
    numberOfElements = 0;
    capacity = 100; // it is ok but we have allocate function it would be better if we use it
    myArray = new T[capacity]; //no pointer declare here
}


template <class T>
MinQueue<T>::MinQueue(T* A, int n) {
    /*
    This constructor basically takes in an array
    and the side of the array and initializes into the
    min heap class.
    */
    if (n < 0) {
        throw std::invalid_argument("n must be non-negative");
    }
    numberOfElements = n;
    capacity = n + 100;
    myArray = new T[capacity];
    for (int i = 0; i < numberOfElements; i++) {
        myArray[i] = A[i];
    } 
    build_heap(); //call build heap here as we need a heap not a normal array
}

template <class T>
MinQueue<T>::~MinQueue() {
    /*
    This is the destructor. This basically frees
    allcated memory and makes eveything go back to zero and capacity to 0
    Then what ever myArray points to will be a nullptr.
    */
    numberOfElements = 0;
    capacity = 0;
    delete[] myArray;
    myArray = nullptr;
}

template <class T>
MinQueue<T>::MinQueue(const MinQueue<T>& other){
    /*
    This is my copy constructor. This basically aquires 
    the capacity of the other and the numberOf Elements and 
    copies others arrays into my created array
    */
    numberOfElements = other.numberOfElements;
    capacity = other.capacity;
    myArray = new T[capacity];
    for (int i = 0; i < numberOfElements; i++) {
        myArray[i] = other.myArray[i];
    } 
}

template <class T>
MinQueue<T>& MinQueue<T>::operator=(const MinQueue<T>& other) {
    /*
    This is my equal operator overload which takes a MinQueue and returns 
    itself first it will delte everything in itself first. 
    */


    if (this == &other) {
        return *this;
    }
    delete[] myArray;
    numberOfElements = other.numberOfElements;
    capacity = other.capacity;
    myArray = new T[capacity];

    for(int i = 0; i < numberOfElements; i++) {
        myArray[i] = other.myArray[i];
    }

    return *this;

}



template <class T>
void MinQueue<T>::insert(T x) {
    allocate(numberOfElements + 1);
    int i = numberOfElements++;
    myArray[i] = x;
    // bubble up to maintain min-heap property
    while (i > 0 && myArray[parent(i)] > myArray[i]) {
        swapIndex(i, parent(i));
        i = parent(i);
    }
}


template <class T>
T MinQueue<T>::min() const{
    if (numberOfElements == 0) {
        throw std::runtime_error("Heap is empty");
    }
    return myArray[0]; //return root
}
template <class T>
T MinQueue<T>::extract_min(){
    if (numberOfElements == 0) {
        throw std::runtime_error("MinQueue underflow");
    }
    T root = myArray[0];
    myArray[0] = myArray[numberOfElements-1]; //assgin last element to the the root;
    --numberOfElements;   
    if (numberOfElements > 0){
        min_heapify(0);            // restore heap property
    }
    return root;
}
template <class T>
void MinQueue<T>::decrease_key(int i, T k){
    if (i < 0 || i >= numberOfElements) {
        throw std::runtime_error("index out of range");
    }
    if(k > myArray[i]){
        throw std::runtime_error("new key is larger than current key");
    }
    myArray[i] = k;
    while(i>0 && myArray[parent(i)]> myArray[i]){
        swapIndex(i, parent(i));
        i = parent(i);
    }
}

template <class T>
void MinQueue<T>::min_heapify(int i) {
    /*
    This is the min_heapify method. The precondition of this method is overall 
    the children are heaps and the post condition is index i will then be a heap. 
    This runs recursively until index i is a heap. 
    */
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < numberOfElements && myArray[l] < myArray[smallest]) {
        smallest = l;
    }
    if (r < numberOfElements && myArray[r] < myArray[smallest]) {
        smallest = r;
    }

    if (smallest != i) {
        swapIndex(smallest, i);
        min_heapify(smallest);
    }
}



template <class T> 
void MinQueue<T>::build_heap() {
    if (numberOfElements <= 1) return;
    for (int i = (numberOfElements / 2) - 1; i >= 0; --i) {
        min_heapify(i);
    }
}


template <class T> 
void MinQueue<T>::sort(T* A){
   if (A == nullptr || numberOfElements == 0) return;

    // Make a copy of this queue so we don't destroy the original
    MinQueue<T> temp;
    temp.allocate(numberOfElements);
    for (int i = 0; i < numberOfElements; i++) {
        temp.set(i, myArray[i]);
    }
    temp.build_heap();

    // Repeatedly extract min into A
    for (int i = 0; i < numberOfElements; i++) {
        A[i] = temp.extract_min();
    }
}

template <class T> 
void MinQueue<T>::set(int i, T val){
    if(i<0){
        throw std::runtime_error("out of index");
    }
    if(i>=capacity){
        allocate(i+1);
    }
    if(i>=numberOfElements){
        numberOfElements = i+1;
    }
    myArray[i] = val;
}

template <class T> 
void MinQueue<T>::allocate(int n){
    if (n <= capacity){
        return;
    }
    int newCap = std::max(n , std::max(2, capacity*2));
    T* newArray = new T[newCap];
    capacity = newCap;
    for(int i = 0; i<numberOfElements; i++){
        newArray[i] = myArray[i];
    }
    delete[] myArray;
    myArray = newArray;
}

template <class T> 
std::string MinQueue<T>::to_string() const{
    std::stringstream s;

    if (numberOfElements > 0) {
        s << myArray[0];  // first element (no leading space)

        for (int i = 1; i < numberOfElements; i++) {
            s << " " << myArray[i];  // prefix each with a space
        }
    }

    return s.str();
}

template <class T>
void MinQueue<T>::printHeap() const { 
    /*
    This is a method to see what is going on for debugging purposes
    */
    for (int i = 0; i < numberOfElements; i++) {
        cout << "Element " << i << " is " << myArray[i] << ". " << endl;
    }
}

template <class T> 
void MinQueue<T>::clear() {
    /*
    This is the clear function it is pretty simple 
    i will delete the array and make it empty with zero elements
    */
    delete[] myArray;
    capacity = 100;
    numberOfElements = 0;
    myArray = new T[capacity];
}
template <class T>
int MinQueue<T>::parent(int i) const {
    assert(i > 0);
    return (i - 1) / 2;
}
template <class T>
int MinQueue<T>::left(int i) const {
    return (2 * i) + 1;
}
template <class T>
int MinQueue<T>::right(int i) const {
    return (2 * i) + 2;
}
template <class T>
void MinQueue<T>::swapIndex(int indexA, int indexB) {
    // This simply just swapIndexs/
    T tempValue = myArray[indexB];
    myArray[indexB] = myArray[indexA];
    myArray[indexA] = tempValue;
}

