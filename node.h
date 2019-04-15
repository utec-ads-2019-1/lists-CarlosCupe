#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;

    void killSelf() {
        // TODO
        if (this->next != nullptr)
            this->next->killSelf();
        
        delete this->next;
        delete this->prev;
    }
};

#endif