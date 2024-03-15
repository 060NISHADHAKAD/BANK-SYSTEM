#ifndef DLL_QUEUE
#define DLL_QUEUE

#include "list.h"   // Include the custom list header file
using namespace std;

// Define a Queue class template
template<class T>
class Queue {

    private:
        DoublyLinkedList<T> lst;    // List to store queue elements
        
    public:
        Queue() {}  // Constructor

        // Clear the queue
        void clear() {
            lst.clear();    // Clear the list
        }

        // Check if the queue is empty
        bool isEmpty() const {
            return lst.empty(); // Check if the list is empty
        }

        // Get the front element of the queue
        T& front() {
            return lst.front(); // Return the first element in the list
        }

        // Remove and return the front element of the queue
        T dequeue() {
            T el = lst.front(); // Get the first element
            lst.pop_front();    // Remove the first element
            return el;          // Return the removed element
        }

        // Add an element to the back of the queue
        void enqueue(const T& el) {
            lst.push_back(el);  // Add an element to the end of the list
        }
};

#endif
