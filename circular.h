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
            return this->head->data;
        }

        T back() {
            // TODO
            return this->tail->data;
        }

        void push_front(T value) {
            // TODO
            Node<T> *temp = new Node<T>;
            temp->data = value;

            if(this->head != nullptr) {
                this->head->prev = temp;
                temp->next = this->head;
            }
            
            this->head = temp;

            if(this->tail == nullptr)
                this->tail = temp;

            this->nodes++;
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
            if (this->nodes == 0)
                exit(0);
                
            Node<T> *ptr = this->head;
            
            while (index--) {
                ptr = ptr->next;
            }
            return ptr->data;
        }

        bool empty() {
            // TODO
            return this->nodes == 0;
        }

        int size() {
            // TODO
            return this->nodes;
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