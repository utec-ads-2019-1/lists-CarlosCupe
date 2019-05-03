#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../iterator.h"

template <typename T> 
class BidirectionalIterator : public Iterator<T> {
    public:
        BidirectionalIterator() : Iterator<T>() {};
        BidirectionalIterator(Node<T> *node) : Iterator<T>(node) {};

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> other) {
            // TODO
            this->current = other.current;
            // Debes retornar *this
            //return this;

            return *this;
        }

        bool operator!=(BidirectionalIterator<T> other) {
            // TODO
            return this->current != other.current;
        }

        BidirectionalIterator<T> operator++() {
            // TODO
            if (this->current)
                this->current = this->current->next;
            return *this;
        }

        BidirectionalIterator<T> operator--() {
            // TODO
            if (this->current)
                this->current = this->current->prev;
            return *this;
        }

        T operator*() {
            // Si está vacía la lista?
            return this->current->data;
        }
};

#endif