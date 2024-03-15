#include <iostream>

// Node class template
template<class T>
class ListNode {
public:
    T data;
    ListNode<T>* next;
    ListNode<T>* prev;

    // Constructor
    ListNode(T newData, ListNode<T>* newNext = nullptr, ListNode<T>* newPrev = nullptr) {
        data = newData;
        next = newNext;
        prev = newPrev;
    }
};

// DoublyLinkedList class template
template<class T>
class DoublyLinkedList {
private:
    ListNode<T>* head;  // Pointer to the head (first node) of the list
    ListNode<T>* tail;  // Pointer to the tail (last node) of the list
    int size;           // Size of the list

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Destructor
    ~DoublyLinkedList() {
        clear();
    }

    // Clear the list
    void clear() {
        while (head != nullptr) {
            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    // Check if the list is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Get the size of the list
    int getSize() const {
        return size;
    }

    // Insert an element at the front of the list
    void push_front(T newData) {
        if (isEmpty()) {
            head = tail = new ListNode<T>(newData);
        } else {
            head->prev = new ListNode<T>(newData, head);
            head = head->prev;
        }
        size++;
    }

    // Remove and return the element at the front of the list
    T pop_front() {
        if (isEmpty()) {
            throw std::runtime_error("List is empty. Cannot pop from an empty list.");
        }

        T data = head->data;
        ListNode<T>* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        size--;
        return data;
    }

    // Insert an element at the back of the list
    void push_back(T newData) {
        if (isEmpty()) {
            head = tail = new ListNode<T>(newData);
        } else {
            tail->next = new ListNode<T>(newData, nullptr, tail);
            tail = tail->next;
        }
        size++;
    }

    // Remove and return the element at the back of the list
    T pop_back() {
        if (isEmpty()) {
            throw std::runtime_error("List is empty. Cannot pop from an empty list.");
        }

        T data = tail->data;
        ListNode<T>* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        size--;
        return data;
    }
};
