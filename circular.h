#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"
#include <string>

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

        T front() {
            // TODO
        }

        T back() {
            // TODO
        }

        void push_front(T value) {
            // TODO
        }

        void push_back(T value) {
            // TODO
        }

        void pop_front() {
            // TODO
        }

        void pop_back() {
            // TODO
        }

        T operator[](int index) {
            // TODO
        }

        bool empty() {
            // TODO
        }

        int size() {
            // TODO
        }

        void clear() {
            // TODO
            while(this->nodes)
                this->pop_back();
        }

        void sort() {
            // TODO
        }
    
        void reverse() {
            // TODO
            int temp = this->nodes;
            Node<T> *ptr = this->tail;
            while(temp--) {
                swap(ptr->next, ptr->prev);
                ptr = ptr->next;
            }
        }

        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
            // TODO
        }

	    BidirectionalIterator<T> end() {
            // TODO
        }

        void merge(CircularLinkedList<T> list) {
            // TODO
            for (int i = 0; i < list.size(); ++i)
                this->push_back(list[i]);
        }
};

#endif