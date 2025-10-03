// ************************************
//  test_minqueue_example.cpp
//  CS 271
//  Harrison Tests
//
// ************************************
#include <iostream>
#include "MinQueue.h"
#include <chrono>
#include <stdexcept>

using namespace std;

void harrisonTestMinQueue() {
    cout << "This is harrisonTestMinQueue(): Test1 " << endl;
    int* myList;
    myList = new int[20];
    for (int i = 0; i < 20; i++) {
        myList[i] = i;
    }
    MinQueue<int> emptyQueue;
    string emptyString = emptyQueue.to_string(); // It is expected to basically be empty.

    MinQueue<int> filledQueue(myList, 20);
    string filledString = filledQueue.to_string(); // This will basically append each item and print out everything

    cout << emptyString << " <-This is the the empty string." << endl;
    cout << filledString <<  " <-This is the the filled string." << endl;

    /*
    I will then use the copy constructor to copy the filled Queue the to_string it
    After that. I will basically have it equal the empty and to_string() it one more time. 
    */
    MinQueue<int> copiedQueue(filledQueue);
    string copiedString = copiedQueue.to_string();
    cout << copiedString;


    copiedQueue = emptyQueue;

    string newCopiedString = copiedQueue.to_string();

    cout << copiedString << " <-This is the the copied string." << endl;
    cout << newCopiedString <<  " <-This is the the copied string after operator overload" << endl;
    cout << "End of Test" <<endl;

}

void harrisonTestInsert() {
    cout << " This is Test 2 harrisonTestInsert()" << endl;
    int staticArray[20] = {37, 82, 14, 59, 63, 28, 92, 5, 71, 46, 33, 90, 17, 64, 7, 55, 100, 22, 84, 11};

    int* randomValues;
    randomValues = new int[20];

    for (int i = 0; i < 20; i++) {
        randomValues[i] = staticArray[i];
    }

    MinQueue<int> insertTestQueue(randomValues, 20);

    string insertTestQueueString = insertTestQueue.to_string();
    cout << insertTestQueueString  << "<- This is the the randQueue string. It will be build heaped" << endl;

    /*
    Then I will insert something that should be in the end. Something that should be in the middle
    and something that should be in the top.
    */

    cout << "Based off what was to stringed I should basically insert a 4 for min 40 for middle and 120 for end" << endl;

    insertTestQueue.insert(4);
    insertTestQueue.insert(40);
    insertTestQueue.insert(120);

    string adjustedTestQueueString = insertTestQueue.to_string();

    cout << adjustedTestQueueString  << "<- This is the the randQueue string with the new items inserted. It will be build heaped" << endl;

    cout << "End of Test" <<endl;
    cout << " " << endl; 
    cout << " " << endl; 
    cout << " " << endl; 



}






void harrisonTestMin() {
    /*
    I will basically use the previous random list in order to test the 
    min function. 
    */
    cout << " This is Test 3 harrisonTestMin()" << endl;
    int staticArray[20] = {37, 82, 14, 59, 63, 28, 92, 5, 71, 46, 33, 90, 17, 64, 7, 55, 100, 22, 84, 11};

    int* randomValues;
    randomValues = new int[20];

    for (int i = 0; i < 20; i++) {
        randomValues[i] = staticArray[i];
    }

    cout << " I will do extract min on my heap with an empty Queue, so it basically throws and error." <<endl;
    try{
        MinQueue<int> emptyQueue;
        int min = emptyQueue.min();
    }
    catch (exception &e)
    {
        // expect an underflow error
        cout << "There is an error that was caught " << e.what() << endl;
    }
    MinQueue<int> filledQueue(randomValues, 20);

    int theActualMin = filledQueue.min();
    cout << theActualMin << endl;
    cout << "The method I just ran should say that 5 is the minimum." << endl;


    cout << "End of Test" <<endl;
    cout << " " << endl; 
    cout << " " << endl; 
    cout << " " << endl; 
    
    


}


void harrisonTestExtractMin() {
    /*
    This test funciton will work to extract min during empty to display an 
    error also. This will also work towards extracting mins of filled Queues to 
    show that it works
    */
    cout << " This is Test 4 harrisonTestExtractMin()" << endl;
    int staticArray[20] = {8, 44, 23, 1};

    int* randomValues;
    randomValues = new int[4];

    for (int i = 0; i < 4; i++) {
        randomValues[i] = staticArray[i];
    }

    cout << " I will do extract min on my heap with an empty Queue, so it basically throws and error." <<endl;
    try{
        MinQueue<int> emptyQueue;
        int min = emptyQueue.extract_min();
    }
    catch (exception &e)
    {
        // expect an underflow error
        cout << "There is an error that was caught You can not extract min" << e.what() << endl;
    }
    MinQueue<int> filledQueue(randomValues, 4);
    string oldString = filledQueue.to_string();
    cout << oldString << " our filled string has four elements after running the method twice the filled string will have two elements" <<endl;
    filledQueue.extract_min();
    filledQueue.extract_min();

    string newString = filledQueue.to_string();
    cout << newString << "This is the new string with only 2 elements " << endl;


    cout << "End of Test" <<endl;
    cout << " " << endl; 
    cout << " " << endl; 
    cout << " " << endl; 
    
    
}


void harrisonTestDecreaseKey() {
    cout << "This is test 5 which is harrisonTestDecreaseKey()" << endl;
    /*
    What I will do in this test per say is basically what I will do. 
    Case 1: I will chose index to be less then zero to basically get the run time error
    Case2: I will make my key greater than myArray[i] to get another run time error
    Case3: Make the key less and within bounds of the array

    */
 
    int staticArray[20] = {8, 44, 23, 1};

    int* randomValues;
    randomValues = new int[4];
    // Try for case 1
    for (int i = 0; i < 4; i++) {
        randomValues[i] = staticArray[i];
    }
    try{
        MinQueue<int> emptyQueue;
        emptyQueue.decrease_key(-1, 12);
    }
    catch (exception &e)
    {
        // expect an underflow error
        cout << "Since you chose -1 there is an error. " << e.what() << endl;
    }
    // Try for case 2
    try{
        MinQueue<int> filledQueue(randomValues, 4);
        filledQueue.decrease_key(1, 100);
    }
    catch (exception &e)
    {
        // expect an underflow error
        cout << "Since the key is to big the is is the error -> " << e.what() << endl;
    }
    // Try for case 3

    try{
        cout << "Before running this will end up succesful" << endl;
        MinQueue<int> otherFilled(randomValues, 4);
        otherFilled.decrease_key(1, 1);
        cout << "After running this is succesful" << endl;

    }
    catch (exception &e)
    {
        // expect an underflow error
        cout << "This will never run if it runs there is an error" << e.what() << endl;
    }


    cout << "End of Test" <<endl;
    cout << " " << endl; 
    cout << " " << endl; 
    cout << " " << endl; 
    
    
}

void harrisonTestMinHeapifyy() {
    cout << "This is Test 6 of harrisonTestMinHeapify()" <<endl;
    /*
    Basically what I am doing is harrisonTestMinHeapify is basically. I will l
    */
    cout << "End of Test" <<endl;
    cout << " " << endl; 
    cout << " " << endl; 
    cout << " " << endl; 
    
    
}
void harrisonTestBuildHeap() {
    cout << "This is Test 7 of harrisonTestMinHeapify()" <<endl;
    /*
    Basically what I am doing is harrisonTestMinHeapify is basically. I will l
    */
    int staticArray[20] = {37, 82, 14, 59, 63, 28, 92, 5, 71, 46, 33, 90, 17, 64, 7, 55, 100, 22, 84, 11};

    int* randomValues;
    randomValues = new int[20];

    for (int i = 0; i < 20; i++) {
        randomValues[i] = staticArray[i];
    }
    cout << " Now we are going to sort it. " <<endl;
    MinQueue<int> sortTestQueue(randomValues, 20);
    string myString = sortTestQueue.to_string();
    cout << "Pre sort this is my string" << myString;

    sortTestQueue.sort(randomValues);

    myString = sortTestQueue.to_string();
    cout << "Post sort this is my string" << myString;

    cout << "End of Test" <<endl;
    cout << " " << endl; 
    cout << " " << endl; 
    cout << " " << endl; 
    
    
}

void harrisonTestHeapSort() {
    cout << "This is Test 8 of harrisonTestMinSort()" <<endl;
    /*
    Basically what I am doing is harrisonTestMinHeapify is basically. I will l
    */
    int staticArray[20] = {37, 82, 14, 59, 63, 28, 92, 5, 71, 46, 33, 90, 17, 64, 7, 55, 100, 22, 84, 11};

    int* randomValues;
    randomValues = new int[20];

    for (int i = 0; i < 20; i++) {
        randomValues[i] = staticArray[i];
    }
    // This the Case 1 for empty.
    try {
        /*
        This is the case One for the empty string
        */
       int* empty = new int[0];
       MinQueue<int> forEmpty;
       forEmpty.sort(empty);
    } catch (exception &e)   {
        cerr << "Since it is empty it can't sort " << e.what() << endl;
    }
    cout << " Now we are going to sort it. " <<endl;
    MinQueue<int> sortTestQueue(randomValues, 20);
    string myString = sortTestQueue.to_string();
    cout << "Pre sort this is my string" << myString <<endl;

    sortTestQueue.sort(randomValues);

    string newString = sortTestQueue.to_string();
    cout << "Post sort this is my string" << newString;

    cout << "End of Test" <<endl;
    cout << " " << endl; 
    cout << " " << endl; 
    cout << " " << endl; 
    
    
}