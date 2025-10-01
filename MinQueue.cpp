#include <cassert>
#include "MinQueue.h"
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
    buildHeap(); //call build heap here as we need a heap not a normal array
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
    /*
    This is the insert method basically. I will insert a node at the 
    last element of the heap and trickel up ward until it 
    statisfies the heap condition again. 
    */
    allocate(numberOfElements+1) //use allocate function
    myArray[numberOfElements] = x;
    numberOfElements = numberOfElements + 1;
    int addedNodedIndex = numberOfElements - 1;
    while (addedNodedIndex > 0 && myArray[addedNodedIndex] < myArray[parent(addedNodedIndex)]) {
        swap(addedNodedIndex, parent(addedNodedIndex));
        addedNodedIndex = parent(addedNodedIndex);
    }
}



template <class T>
void MinQueue<T>::minHeapify(int i) {
    /*
    This is the minHeapify method. The precondition of this method is overall 
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
        swap(smallest, i);
        minHeapify(smallest);
    }
}

template <class T> 
void MinQueue<T>::buildHeap() {
    for (int i = parent(numberOfElements - 1) / 2; i >= 0; i--) {
        minHeapify(i);
    }
}

template <class T>
void MinQueue<T>::printHeap() {
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
void MinQueue<T>::swap(int indexA, int indexB) {
    // This simply just swaps/
    T tempValue = myArray[indexB];
    myArray[indexB] = myArray[indexA];
    myArray[indexA] = tempValue;
}
