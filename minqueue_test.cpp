// ************************************
//  minqueue_test.cpp
//  CS 271
//  Project 2
//  An - Harrison
// ************************************
#include <iostream>
#include "MinQueue.h"
#include <chrono>
#include <stdexcept>
#include "harrisonTest.cpp"
using namespace std;

void test_minqueue()
{

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        string mq_str = empty.to_string();

        if (mq_str != "")
        {
            cout << "Incorrect result from empty constructor. Expected an empty string but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        mq_str = mq.to_string();

        if (mq_str != "1 2 4 3 6 5 8 10 7 9")
        {
            cout << "Incorrect result from empty constructor. Expected 1 2 4 3 6 5 8 10 7 9 but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error creating the priority queue : " << e.what() << endl;
    }

    delete[] int_data;

    /*
    Harrison's Extensive Tests. What I noticed is that There are no opeator equals and destrutors 
    So basically I will test for copy constructor as wells as for opeator equals.
    */

   try {
        MinQueue<int> filledQueue(int_data, 10);
        string filledToString = filledQueue.to_string();

        if (filledToString != "1 2 4 3 6 5 8 10 7 9")
        {
            cout << "Incorrect result from empty constructor. Expected 1 2 4 3 6 5 8 10 7 9 but got : " << filledToString << endl;
        }
        // So I just filled the string values and now I will utilize copy constructor on filledQueue and 
        // Then I will other queue called operator queue with operator overload and then to string them. 
        MinQueue<int> copyQueue(filledQueue);

        string copyString = filledQueue.to_string();

        if (copyString != "1 2 4 3 6 5 8 10 7 9")
        {
            cout << "Incorrect result from empty constructor. Expected 1 2 4 3 6 5 8 10 7 9 but got : " << copyString << endl;
        }
        MinQueue<int> operatorEqualsQueue = copyQueue;

        string opeatorEqualsString = filledQueue.to_string();

        if (opeatorEqualsString != "1 2 4 3 6 5 8 10 7 9")
        {
            cout << "Incorrect result from empty constructor. Expected 1 2 4 3 6 5 8 10 7 9 but got : " << opeatorEqualsString << endl;
        }

   } catch (exception &e) {
        cout << "There is an error in either of the constructors.  " << endl;
   }



}

void test_insert()
{

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
        
    }

    try
    {

        MinQueue<int> empty;
        empty.insert(0);
        string mq_str = empty.to_string();

        if (mq_str != "0")
        {
            cout << "Incorrect insert result. Epected 0 but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        mq.insert(25);
        mq.insert(0);
        mq_str = mq.to_string();

        if (mq_str != "0 2 1 3 6 4 8 10 7 9 25 5")
        {
            cout << "Incorrect insert result. Expected 0 2 1 3 6 4 8 10 7 9 25 5 but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error inserting into the priority queue : " << e.what() << endl;
    }

    delete[] int_data;

    /*
    I am adding an extensive test to test our allocate helper function in the background by adding 101 items 
    in the queue when we have a capacity of 101.
    */
   
   try {
        MinQueue<int> stringQueue;
        for (int i = 0; i < 105; i++) {
            stringQueue.insert(800);
        }
   } catch (exception &e) {
        cout << "Allocate is exhausted" << endl;
   }
}

void test_min()
{

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try{
        MinQueue<int> empty;
        int min = empty.min();
        string mq_str = empty.to_string();
        cout << "Incorrectly returned min from empty queue: " << min << endl;
    }
    catch (exception &e)
    {
        // expect an underflow error
        cout << "Correctly caught error trying to get min from empty queue: " << e.what() << endl;
    }

    try
    {
        MinQueue<int> mq(int_data, 10);
        int min = mq.min();
        if (min != 1)
        {
            cout << "Incorrect min result. Expect 0 but got : " << min << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    }
    /*
    In this exhuastive test I am basically going to insert a really small value and assert that the min will
    equal that value to make sure it the insert is truly inserting the values correctly and the min is getting the right
    value
    */
   try {
        MinQueue<int> MinQueueExhaustive(int_data, 10); // I basically made a new one and i added int_data
        int reallyLowValue = -100000;
        MinQueueExhaustive.insert(reallyLowValue); 
        /*
        I inserted a really low value. Then I will make sure that 
        my min is that value or else I will throw an error.
        */
        int min = MinQueueExhaustive.min();

        if (min != reallyLowValue) {
            throw std::runtime_error("Improper minimum bro.");
        }
        cout << "No error was thrown." << endl;


   } catch (exception &e) {
        cerr << "" << e.what() << endl;
    }

    delete[] int_data;
}

void test_extract_min()
{

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try{
        MinQueue<int> empty;
        int min = empty.extract_min();
        string mq_str = empty.to_string();
        cout << "Incorrectly extracted min from empty queue: " << min << endl;
    }
    catch (exception &e)
    {
        // expect an underflow error
        cout << "Correctly caught error trying to extract min from empty queue: " << e.what() << endl;
    }
    try
    {
        MinQueue<int> mq(int_data, 10);
        int min = mq.extract_min();
        string mq_str = mq.to_string();

        if (min != 1 || mq_str != "2 3 4 7 6 5 8 10 9")
        {
            cout << "Incorrect extract min result. Expected 0 and the queue 2 3 4 7 6 5 8 10 9 but got : " << min << " and a queue of : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    }

    /*
    In my exhaustive measure I will add about five elements then I will run a for loop to extractMinimum 20 times so 
    at the sixth iteration we should expect an error.
    */
   MinQueue<int> exhaust;
   try {
        exhaust.insert(12);
        exhaust.insert(88);
        exhaust.insert(43);
        exhaust.insert(100);
        exhaust.insert(11);
        for (int i = 0; i < 20; i++) {
            exhaust.extract_min();
        }
   } catch (exception &e) {
        cout << "The loop did not finish, but the list empty" << endl;
        string exhaustString = exhaust.to_string();
        cout << exhaustString << "This string is empty since all is removed" << endl;

   }


    delete[] int_data;
}

void test_decrease_key()
{

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {
        MinQueue<int> mq(int_data, 10);
        mq.decrease_key(0, -6);
        mq.decrease_key(9, -1);
        string mq_str = mq.to_string();

        if (mq_str != "-6 -1 4 3 2 5 8 10 7 6")
        {
            cout << "Incorrect decrease key result. Expected empty queue but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in decreasing key : " << e.what() << endl;
    }

    delete[] int_data;

    /*
    For my exhaustive I will use an index of -1.
    */

   try {
        MinQueue<int> exhaust; // As you can see I love the word exhaust.
        exhaust.insert(5); // Will insert 5 but then I will try to change the key in index - 1
        exhaust.decrease_key(-1, 2);

   } catch (exception& e) {
        cerr << "Index is less than 0" << endl;

   }

       /*
    For my exhaustive I will use an index of greater than numberOf Elements
    */

   try {
        MinQueue<int> exhaust; // As you can see I love the word exhaust.
        exhaust.insert(5); // Will insert 5 but then I will try to change the key in index - 1
        exhaust.decrease_key(100, 2);

   } catch (exception& e) {
        cerr << "Index is more than number Of Elements" << endl;

   }
}

void test_heapify()
{

    int *empty_data = new int[0];

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        empty.min_heapify(1);
        string mq_str = empty.to_string();

        if (mq_str != "")
        {
            cout << "Incorrect heapify result. Expected empty string but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        string o_mq_str = mq.to_string();
        mq.set(1, 11);
        mq.min_heapify(1);

        mq_str = mq.to_string();

        if (mq_str != "1 3 4 7 6 5 8 10 11 9")
        {
            cout << "Incorrect heapify result in heapifying index 1 in the minqueue " << o_mq_str << " after setting to 11. Expected 1 3 4 7 6 5 8 10 11 9 but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in heapify : " << e.what() << endl;
    }
    /*
    Dr. Currin tested min heapify for elemets that were in range. my exhuast minque will do it for out of range.
    */

    try {
        MinQueue<int> exhaust;
        exhaust.min_heapify(-100);

    } catch(exception &e) {
        cout << "Index out of range" <<endl;
    }

    /*
    I am min heapififying when i is greater than number of elements.
    */

    try {
        MinQueue<int> exhaustTwo;
        exhaustTwo.min_heapify(100);

    } catch(exception &e) {
        cout << "Index out of range due to being more than number of elements" <<endl;
    }

    /*
    Lastly I will heapify when i is 0 which is basically a boundary case.
    */
    try {
        MinQueue<int> exhaustThree(int_data, 10);
        exhaustThree.min_heapify(0);
        cout << "There is no failure on boundary case" << endl;

    } catch(exception &e) {
        cout << "Index zero caused a failure";
    }

    delete[] empty_data;
    delete[] int_data;
}

void test_build_min_heap()
{

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> mq;
        mq.allocate(10);
        for (int i = 0; i < 10; i++)
        {
            mq.set(i, int_data[i]);
        }
        string o_mq_str = mq.to_string();

        mq.build_heap();
        string mq_str = mq.to_string();

        if (mq_str != "1 2 4 3 6 5 8 10 7 9")
        {
            cout << "Incorrect build_heap result from " << o_mq_str << ". Expected 1 2 4 3 6 5 8 10 7 9 but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in building min heap : " << e.what() << endl;
    }
    /*
    For my entensive test I will build min heap on with an empty heap. and a heap with one element
    Based on the post condition we should expect the heap to basically reutrn than run. Then I will 
    to_string it and it will be either empty or the only one object.
    */
   try {
        MinQueue<int> empty;
        MinQueue<int> withOne;
        withOne.insert(5); // Now has only one element.

        // I will build heap with both and basically return the to Strings.

        string emptyString = empty.to_string();
        string withOneString = withOne.to_string();

        if (emptyString != "") {
            throw std::runtime_error("Wrong String");
        }
        if (withOneString != "5") {
            throw std::runtime_error("Wrong String");
        }
   } catch (exception &e) {
        cerr << " there is a caught err" << endl;
   }

    delete[] int_data;
}

void test_heapsort()
{

    int *empty_data = new int[0];

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        empty.sort(empty_data);

        MinQueue<int> heap(int_data, 10);
        heap.sort(int_data);

        string sorted_str = to_string(int_data[0]);

        for (int i = 1; i < 10; i++)
        {
            sorted_str += (" " + to_string(int_data[i]));
        }

        if (sorted_str != "1 2 3 4 5 6 7 8 9 10")
        {
            cout << "Incorrect heapsort result. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << sorted_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in sorting : " << e.what() << endl;
    }
    /*
    What if per say that the array is a nullptr since we are using dynamic arrays so 
    So I will create a dyamic array make it equal null. It is expected to just return.
    */

    try {
        int* dyanamicNullArray = nullptr;
        MinQueue<int> nullQueue(dyanamicNullArray, 0);
    } catch (exception &e) {
        cout << "We caught the error and the array is null therefore it can be created anyways, nor sorted.)" <<endl;

    }
    delete[] empty_data;
    delete[] int_data;
}

// use an enum to represent class year
enum Year {SR, JR, SO, FR};

// define a struct representing a student record
struct StudentRecord
{
    string name;
    Year year;
    // set registration time to the current time when the student record is created
    std::chrono::system_clock::time_point registration_time = std::chrono::system_clock::now();

    // overload < operator to compare students based on year and registration time
    bool operator<(const StudentRecord &other) const
    {
        return (year < other.year) || (year == other.year && registration_time < other.registration_time);
    }

    // overload > operator to compare students based on year and registration time
    bool operator>(const StudentRecord &other) const
    {
        return (year > other.year) || (year == other.year && registration_time > other.registration_time);
    }

    // overload == operator to compare students based on year and registration time
    bool operator==(const StudentRecord &other) const
    {
        return (year == other.year && registration_time == other.registration_time);
    }

    // overload != operator to compare students based on year and registration time
    bool operator!=(const StudentRecord &other) const 
    {
        return (year != other.year || registration_time != other.registration_time);
    }
    
    // overload <= operator to compare students based on year and registration time
    bool operator<=(const StudentRecord &other) const
    {
        return (year < other.year) || (year == other.year && registration_time <= other.registration_time);
    }

    // overload >= operator to compare students based on year and registration time
    bool operator>=(const StudentRecord &other) const
    {
        return (year > other.year) || (year == other.year && registration_time >= other.registration_time);
    }

    // overload << operator to print student record
    friend ostream &operator<<(ostream &os, const StudentRecord &student)
    {
        string year_str;
        switch (student.year)   
        {
            case SR: year_str = "Senior"; break;
            case JR: year_str = "Junior"; break;
            case SO: year_str = "Sophomore"; break;
            case FR: year_str = "Freshman"; break;
            default: year_str = "Unknown"; break;
        }
        os << student.name << " (" << year_str << ")";
        return os;
    }
};

void test_application_waitlist()
{
    // create a minqueue of students
    MinQueue<StudentRecord> waitlist;
    waitlist.insert({"Alice", SR});
    waitlist.insert({"Bob", JR});
    waitlist.insert({"Charlie", SO});
    waitlist.insert({"David", FR});
    waitlist.insert({"Eve", SR});
    waitlist.insert({"Frank", JR});
    waitlist.insert({"Grace", SO});
    waitlist.insert({"Heidi", FR});
    waitlist.insert({"Ivan", SR});
    waitlist.insert({"Judy", JR});
    waitlist.insert({"Mallory", SO});
    waitlist.insert({"Niaj", FR});
    waitlist.insert({"Olivia", SR});
    waitlist.insert({"Peggy", JR});


    // process the waitlist and print the order in which students are registered
    cout << "Registration order:" << endl;

    // assume there are only 10 spots available
    for (int i = 0; i < 10; i++)
    {
        StudentRecord student = waitlist.extract_min();
        cout << student << endl;
    }
    /*
        After doing so I added a new waitlist called waitlistTwo and I really wanted 
        dive deep so I noticed this test lacked decrease key, because potentially students could 
        evenutally have higher priority. 
    */
   MinQueue<StudentRecord> waitlistNew;
    waitlistNew.insert({"Andrew", SR});
    waitlistNew.insert({"Colin", JR});
    waitlistNew.insert({"Harrison", SO});
    waitlistNew.insert({"An", FR});
    waitlistNew.insert({"Nana", SR});
    waitlistNew.insert({"Dr. Currin", JR});
    
    string classString = waitlistNew.to_string();
    try {
       cout << classString << "<- This is the class string" << endl; 
       cout << "" << endl;
    } catch (exception &e) {
        cerr << "Something went wrong";
    }

    // Now I am going to decrease key with Harrison and make him a sophomre
    // Based of what was on the terminal Harrison is the 5th element. I will make harrison a Senior
    // And since the when harrison moves up the queue his priority will not be greater than Andrew his parent. 

    try {
        waitlistNew.decrease_key(5, {"Harrison",SR});
        string myNewString = waitlistNew.to_string();
        cout << "Post List" << endl;
        cout << " " << endl;
        cout << myNewString << "Harrison Has went up in priority" << endl;
    } catch (exception &e) {
        cerr << "Index out of range";
    }
    

}

void time_test()
{
    MinQueue<int> mq;
    // TO-DO: generate large minqueue
    int size = 10000; // TO-DO: set size of large minqueue
    for (int i = 0; i < size; ++i) {
        mq.insert(rand());                  // fill it up
    }
    int total = 0;

    int val = rand() % 100000;
    auto begin = std::chrono::high_resolution_clock::now();
    mq.insert(val);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "insert time test took " << elapsed.count() << " nanoseconds" << endl;
    total += elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    int _ = mq.min();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "min time test took " << elapsed.count() << " nanoseconds" << endl;
    total += elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    _ = mq.extract_min();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "extract min time test took " << elapsed.count() << " nanoseconds" << endl;
    total += elapsed.count();

    int last_index = size - 1;  // indexing starts at 0
    int new_val = mq.min() - 1; // ensure we're decreasing the key
    begin = std::chrono::high_resolution_clock::now();
    mq.decrease_key(last_index, new_val);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "decrease key time test took " << elapsed.count() << " nanoseconds" << endl;
    total += elapsed.count();
    cout << "Total time: " << total << endl;
}
// Duplicates: insert many duplicates and confirm extraction order is stable wrt key (ties equal keys).
void test_insert_and_extract_with_duplicates() {
    cout << "[test_insert_and_extract_with_duplicates] " << endl;
    try {
        MinQueue<int> mq;
        for (int x : {5,5,5,1,1,2,2,2,5,1}) mq.insert(x);

        vector<int> out;
        while (mq.get_size() > 0) out.push_back(mq.extract_min());

        vector<int> expect = {1,1,1,2,2,2,5,5,5,5};
        if (out != expect) {
            cout << "  FAIL: expected 1 1 1 2 2 2 5 5 5 5 but got: ";
            for (size_t i=0;i<out.size();++i) {
                cout << out[i] << (i+1<out.size()?' ':'\n');
            }
        }else{
            cout << "duplicate test succeeded" << endl;
        }
    } catch (exception& e) {
        cerr << "  ERROR: " << e.what() << endl;
    }
}
// sort with strings (lexicographic), including duplicates and mixed case.
void test_sort_strings_lexi() {
    try {
        const int n = 8;
        string A[n] = {"delta","Bravo","alpha","echo","Alpha","charlie","bravo","delta"};
        MinQueue<string> mq(A, n);
        mq.sort(A);
        // std::string operator< is lexicographic and case-sensitive
        vector<string> got(A, A+n);
        vector<string> expect = {"Alpha","Bravo","alpha","bravo","charlie","delta","delta","echo"};
        if (got != expect) {
            cout << "  FAIL: string heapsort expected: ";
            for (size_t i=0;i<expect.size();++i) cout << expect[i] << (i+1<expect.size()?' ':'\n');
            cout << "        but got: ";
            for (size_t i=0;i<got.size();++i) cout << got[i] << (i+1<got.size()?' ':'\n');
        } else{
            cout << "test heap sort strings (lexicographic) test succeeded" << endl;
        }
    } catch (exception& e) {
        cerr << "  ERROR: " << e.what() << endl;
    }
}

void test_allocate_growth() {
    try {
        MinQueue<int> mq;

        // Insert 200 elements in descending order
        for (int i = 200; i >= 1; --i) {
            mq.insert(i);
        }

        // Now extract them one by one and confirm ascending order
        bool ok = true;
        for (int expected = 1; expected <= 200; ++expected) {
            int got = mq.extract_min();
            if (got != expected) {
                cout << "  FAIL: expected " << expected << " but got " << got << endl;
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "test allocate growth succeeded" << endl;
        }

    } catch (exception& e) {
        cerr << "  ERROR: " << e.what() << endl;
    }
}
int main()
{

    test_minqueue();
    test_insert();
    test_min();
    test_extract_min();
    test_decrease_key();
    test_heapify();
    test_build_min_heap();
    test_heapsort();

    test_application_waitlist();

    time_test();

    test_insert_and_extract_with_duplicates();
    test_sort_strings_lexi();
    test_allocate_growth();

    harrisonTestMinQueue();
    harrisonTestInsert();
    harrisonTestMin();
    harrisonTestExtractMin();
    harrisonTestDecreaseKey();
    harrisonTestHeapSort();


    cout << "Testing completed" << endl;

    return 0;
}