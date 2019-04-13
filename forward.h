#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

        T front() {
            // TODO
            return head->data;
        }

        T back() {
            // TODO
            return tail->data;
        }

        void push_front(T value) {
            // TODO
            Node<T> *temp = New Node<T>;
            temp->next = head->next;
            head = temp;

            if(tail == nullptr)
                tail == temp;

            nodes++;
        }

        void push_back(T value) {
            // TODO
            Node<T> *temp = New Node<T>;
            temp->next = nullptr;
            tail->next = temp;
            tail = temp;

            if (head == nullptr)
                head = temp;

            nodes++;
        }

        void pop_front() {
            // TODO
            if (head == nullptr)
                return
            
            Node<T> *temp = head;
            head = head->next;            
            delete temp;

            if (nodes == 1)
                tail = nullptr;
            nodes--;
        }

        void pop_back() {
            // TODO
            Node<T> *ptr = head;
            
            if (nodes == 1) {
                delete head;
                head = nullptr;
                tail = nullptr;
            }


            while(ptr->next != temp)
                ptr = ptr->next;
            
            ptr->next = nullptr;
            delete tail;

            tail = ptr;
        }

        T operator[](int index) {
            // TODO
            try {
                throw (index == 0);
            }
            catch(bool e) {
                cout << "Index error - La lista esta vacia" << endl;
            }
            
                
            Node<T> *ptr = head;
            
            while (index--) {
                ptr = ptr->next;
            }
            return ptr->data;
        }

        bool empty() {
            // TODO
        }

        int size() {
            // TODO
        }

        void clear() {
            // TODO
        }

        void sort() {
            // TODO
        }
    
        void reverse() {
            // TODO
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
        }
};

#endif