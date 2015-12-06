#ifndef HWLIST
#define HWLIST


#include <iostream>
#include <string>
#include "stdlib.h"


/**
 * The HWList class.
 */
template <class ValueType>
class HWList {
private:
    /**
     * The Node struct.
     */
    struct Node {
        ValueType value;
        Node* next;
        Node* prew;
        Node(ValueType v) {
            value = v;
            next = 0;
            prew = 0;
        }
    };
    Node* head;
    Node* tail;
    int counter;
public:
    /**
     * The HWList::iterator class.
     */
    class iterator {
    private:
        Node* pointer;
    public:
        /**
         * The defaul HWList::iterator constructor.
         */
        iterator() {
            pointer = 0;
        }


        /**
         * The HWList::iterator constructor.
         *
         * @param ptr - The pointer to the node.
         */
        iterator(Node* ptr) {
            pointer = ptr;
        }


        /**
         * Overloading the operator * for the HWList::iterator.
         *
         * @return - The value of the pointed node
         */
        ValueType& operator*() {
            return pointer->value;
        }


        /**
         * Overloading the preincrement operator for the HWList::iterator.
         *
         * @return - The iterator reference.
         */
        iterator& operator++() {
            pointer = pointer->next;
            return *this;
        }


        /**
         * Overloading the postincrement operator for the HWList::iterator.
         *
         * @return - The iterator reference.
         */
        iterator& operator++(int) {
            iterator tmp = *this;
            pointer = pointer->next;
            return tmp;
        }


        /**
         * Overloading the operator == for the HWList::iterator.
         *
         * @param rhs - The right hand side iterator.
         * @return - True if current iterator is equal to the right hand side iterator,
         *           or false in other case.
         */
        bool operator==(iterator rhs) {
            return (pointer == rhs.pointer);
        }


        /**
         * Overloading the operator != for the HWList::iterator.
         * @param rhs - The right hand side iterator.
         * @return - True if current iterator is not equal to the right hand side iterator,
         *           or false in other case.
         */
        bool operator!=(iterator rhs) {
            return (pointer != rhs.pointer);
        }


    };


    /**
     * The HWList default constructor.
     */
    HWList() {
        head = 0;
        tail = 0;
        counter = 0;
    }


    /**
     * The HWList destructor.
     */
    ~HWList() {
        clear();
    }


    /**
     * The HWList copy constructor.
     * @param rhs - The right hand side HWList.
     */
    HWList(const HWList& rhs) {
        head = 0;
        tail = 0;
        counter = 0;
        for (iterator it = rhs.begin(); it != rhs.end(); it++)
            push_back(*it);
    }


    /**
     * Overloading the assign operator for HWList.
     *
     * @param list
     * @return
     */
    HWList& operator=(HWList& rhs) {
        if (this != &rhs) {
            clear();
            for (iterator it = rhs.begin(); it != rhs.end(); it++)
                push_back(*it);
        }
        return *this;
    }


    /**
     * Get the HWList size.
     *
     * @return - The HWList size.
     */
    int size() {
        return counter;
    }


    /**
     * To define whether the HWList is empty.
     *
     * @return - True if the list is empty, or false in other case.
     */
    bool empty() {
        return (size() == 0);
    }


    /**
     * Get the HWList first element value.
     *
     * @return - The first element value.
     */
    ValueType front() {
        if (empty()) {
            std::cerr << "Error! Try front() from empty list." << std::endl;
            exit(EXIT_FAILURE);
        }
        return head->value;
    }


    /**
     * Get the HWList last element value.
     *
     * @return - The last element value.
     */
    ValueType back() {
        if (empty()){
            std::cerr << "Error! Try back() from empty list." << std::endl;
            exit(EXIT_FAILURE);
        }
        return tail->value;
    }


    /**
     * Add the new element to the HWList front end.
     *
     * @param value - The new element value.
     */
    void push_front(ValueType value) {
        Node* newNode = new Node(value);
        if (empty()) {
            tail = newNode;
            head = newNode;
        } else {
            head->prew = newNode;
            newNode->next = head;
            head = newNode;
        }
        counter++;
    }


    /**
     * Add the new element to the HWList back end.
     *
     * @param value - The new element value.
     */
    void push_back(ValueType value) {
        Node* newNode = new Node(value);
        if (empty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prew = tail;
            tail = newNode;
        }
        counter++;
    }


    /**
     * Remove the first element from the HWlist.
     */
    void pop_front() {
        if (empty()) {
            std::cerr << "Error! Try pop_front() from empty list." << std::endl;
            exit(EXIT_FAILURE);
        }
        Node* removedNode = head;
        if (size() > 1) {
            head = removedNode->next;
            head->prew = 0;
        } else {
            head = 0;
            tail = 0;
        }
        delete removedNode;
        counter--;
    }


    /**
     * Remove the last element from the HWList.
     */
    void pop_back() {
        if (empty()) {
            std::cerr << "Error! Try pop_back() from empty list." << std::endl;
            exit(EXIT_FAILURE);
        }
        Node* removedNode = tail;
        if (size() > 1) {
            tail = removedNode->prew;
            tail->next = 0;
        } else {
            tail = 0;
            head = 0;
        }
        delete removedNode;
        counter--;
    }


    /**
     * To clear the HWList.
     */
    void clear() {
        while(!empty())
            pop_back();
    }


    /**
     * Get the HWList::iterator to the first list element.
     *
     * @return - The iterator to the first list element.
     */
    iterator begin() {
        return iterator(head);
    }


    /**
     * Get the HWList::iterator to the next after the last list element.
     *
     * @return - The iterator to the next after the last list element.
     */
    iterator end() {
        return iterator();
    }


};


#endif // HWLIST
