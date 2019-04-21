#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"
#include <string>

template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

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
            Node<T> *temp = new Node<T>;
            temp->data = value;
            
            if (this->tail != nullptr) {
                temp->prev = this->tail;
                this->tail->next = temp;
            }
            
            this->tail = temp;

            if (this->head == nullptr)
                this->head = temp;

            this->nodes++;
        }

        void pop_front() {
            // TODO
            if (this->head == nullptr)
                return;
            
            this->head = this->head->next;

            delete this->head->prev;
            this->head->prev = nullptr;
            this->nodes--;

            if (this->nodes == 0)
                this->tail = nullptr;
        }

        void pop_back() {
            // TODO
            if (this->nodes == 1) {
                delete this->tail;
                this->head = nullptr;
                this->tail = nullptr;
                this->nodes--;
                return;
            }

            this->tail = this->tail->prev;
            
            delete this->tail->next;
            this->tail->next = nullptr;

            this->nodes--;
        }

        T operator[](int index) {
            // TODO
            if (this->nodes == 0 || index >= this->nodes)
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
            this->head->killSelf();
            this->head = this->tail = nullptr;
            this->nodes = 0;
        }

        void sort() {
            // TODO
            if (this->nodes <= 1)
                return;

            T *arr = new T[this->nodes];
            Node<T> *ptr = this->head;

            for (int i = 0; ptr != nullptr; ++i) {
                arr[i] = ptr->data;
                ptr = ptr->next;
            }
            
            std::sort(arr, arr + this->nodes);
            ptr = this->head;

            for (int i = 0; ptr != nullptr; ++i) {
                ptr->data = arr[i];
                ptr = ptr->next;
            }
        }
    
        void reverse() {
            // TODO  
            Node<T> *ptr = this->tail;
            
            do {
                swap(ptr->next, ptr->prev);
                ptr = ptr->next;
            } while(ptr);

            swap(this->tail, this->head);
        }

        string name() {
            return "Linked List";
        }

        BidirectionalIterator<T> begin() {
            // TODO
            return BidirectionalIterator<T>(this->head);
        }

	    BidirectionalIterator<T> end() {
            // TODO
            return nullptr;
        }

        void merge(LinkedList<T> list) {
            // TODO
            for (int i = 0; i < list.size(); ++i) {
                this->push_back(list[i]);
            }
        }
};

#endif