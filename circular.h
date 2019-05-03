#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"
#include <string>

/*
No mezclaste con master
*/
template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

        T front() {
            // Falta controlar el caso vacío
            return this->head->data;
        }

        T back() {
            // Falta controlar el caso vacío
            return this->tail->data;
        }

        void push_front(T value) {
            // TODO
            Node<T> *temp = new Node<T>;
            temp->data = value;

            if(this->head != nullptr) {
                temp->prev = this->tail;
                temp->next = this->head;
                this->tail->next = temp;
                this->head->prev = temp;
            } else {
                temp->prev = temp;
                temp->next = temp;
            }
            
            this->head = temp;

            if(this->tail == nullptr)
                this->tail = temp;
            this->nodes++;
        }

        void push_back(T value) {
            // TODO
            Node<T> *temp = new Node<T>;
            temp->data = value;
            
            if (this->tail != nullptr) {
                temp->prev = this->tail;
                temp->next = this->head;
                this->head->prev = temp;
                this->tail->next = temp;
            }
            
            this->tail = temp;

            if (this->head == nullptr)
                this->head = temp;

            this->nodes++;
        }

        void pop_front() {
            // TODO
            if (this->nodes == 1) {
                delete this->head;
                this->head = this->tail = nullptr;
                return;
            }

            this->head = this->head->next;
            delete this->head->prev;
            this->head->prev = this->tail;
            this->tail->next = this->head;
            this->nodes--;
        }

        void pop_back() {
            // TODO
            if (this->nodes == 1) {
                delete this->tail;
                this->head = this->tail = nullptr;
                this->nodes--;
                return;
            }

            this->tail = this->tail->prev;
            delete this->tail->next;

            this->tail->next = this->head;
            this->head->prev = this->tail;
            this->nodes--;
        }

        T operator[](int index) {
            // Falta controlar el caso vacío
            if (this->nodes == 0)
                exit(0);
                
            index = index % this->nodes;

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
            if(this->nodes <= 1)
                return;

            Node<T> *ptr = this->head->next;
            T *arr = new T[this->nodes];

            arr[0] = this->head->data;

            for (int i = 1; ptr != this->head; ++i) {
                arr[i] = ptr->data;
                ptr = ptr->next;
            }

            std::sort(arr, arr + this->nodes);
            ptr->data = arr[0];
            ptr = ptr->next;

            for (int i = 1; ptr != this->head; ++i) {
                ptr->data = arr[i];
                ptr = ptr->next;
            }
        }
    
        void reverse() {
            // TODO
            Node<T> *ptr = this->head;
            
            do {
                swap(ptr->next, ptr->prev);
                ptr = ptr->next;
            } while(ptr != this->head);
            
            swap(this->head, this->tail);
        }

        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
            // TODO
            return BidirectionalIterator<T>(this->head);
        }

	    BidirectionalIterator<T> end() {
            // Debes retornar otra cosa
            // TODO
            return nullptr;
        }

        void merge(CircularLinkedList<T> list) {
            // TODO
            for (int i = 0; i < list.size(); ++i)
                this->push_back(list[i]);
        }
};

#endif