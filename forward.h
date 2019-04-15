#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "node.h"
#include "iterators/forward_iterator.h"
#include <string>

template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

        T front() {
            // TODO
            if (this->head == nullptr)
                exit(0);
            else
                return this->head->data;
        }

        T back() {
            // TODO
            if (this->head == nullptr)
                exit(0);
            else
                return this->tail->data;            
        }

        void push_front(T value) {
            // TODO
            Node<T> *temp = new Node<T>;
            
            if(this->head == nullptr)
                temp->next = nullptr;
            else
                temp->next = this->head->next;
            
            this->head = temp;

            if(this->tail == nullptr)
                this->tail = temp;

            this->nodes++;
        }

        void push_back(T value) {
            // TODO
            Node<T> *temp = new Node<T>;

            temp->next = nullptr;

            if (this->tail == nullptr)
                this->tail->next = temp;
            
            this->tail = temp;

            if (this->head == nullptr)
                this->head = temp;

            this->nodes++;
        }

        void pop_front() {
            // TODO
            if (this->head == nullptr)
                return;
            
            Node<T> *ptr = this->head;
            this->head = this->head->next;            
            delete ptr;

            if (this->nodes == 1)
                this->tail = nullptr;
            this->nodes--;
        }

        void pop_back() {
            // TODO
            Node<T> *ptr = this->head;
            
            if (this->nodes == 1) {
                delete this->head;
                this->head = nullptr;
                this->tail = nullptr;
            }

            while(ptr->next != this->tail)
                ptr = ptr->next;
            
            ptr->next = nullptr;
            delete this->tail;

            this->tail = ptr;
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
            this->head->killSelf();
            this->head = nullptr;
            this->tail = nullptr;
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
            if (this->nodes <= 1)
                return;

            if (this->nodes == 2) {
                swap(this->head->data, this->tail->data);
                return;
            }
            
            Node<T> *ptr = this->head->next;
            Node<T> *temp = this->head;
            
            temp->next = ptr->next;
            ptr->next = temp;
            
            temp = this->head->next;

            while(temp != nullptr) {
                this->head->next = temp->next;
                temp->next = ptr;
                ptr = temp;
                temp = this->head->next;    
            }
        }

        string name() {
            return "Forward List";
        }

        ForwardIterator<T> begin() {
            // TODO
        }

	    ForwardIterator<T> end() {
            // TODO
        }

        void merge(ForwardList<T> list) {
            // TODO
            for (int i = 0; i < list.size(); ++i) {
                this->push_back(list[i]);
            }
        }
};

#endif