#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node() {
        next = prev = nullptr;
    }

    void killSelf() {
        // TODO       
        if (this->next != nullptr)
            this->next->killSelf();
        delete this;
    }
};

#endif