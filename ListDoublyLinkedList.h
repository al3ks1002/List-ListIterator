#ifndef LISTDOUBLYLINKEDLIST_H_
#define LISTDOUBLYLINKEDLIST_H_

#include "DoublyLinkedList.h"

template<typename T>
class ListDoublyLinkedList {
    public:
        class ListIterator {
            public:
                ListIterator() {}
                ~ListIterator() {}
                ListIterator(DoublyLinkedList<T>* list);
                ListIterator(const ListIterator& that);
                ListIterator& operator=(const ListIterator& that);

                bool has_next() const;
                bool has_previous() const;
                T next();
                T previous();

                void add(T element);
                void set(T element);
                void remove();

            private:
                DoublyLinkedList<T>* list;
                typename DoublyLinkedList<T>::Node* current;
                typename DoublyLinkedList<T>::Node* last;
        };

        ListDoublyLinkedList();
        ~ListDoublyLinkedList();
        ListDoublyLinkedList(const ListDoublyLinkedList<T>& that);
        ListDoublyLinkedList& operator=(const ListDoublyLinkedList<T>& that);

        bool empty();
        int size();
        void clear();

        ListIterator begin();

    private:
        DoublyLinkedList<T>* list;
};

template<typename T>
ListDoublyLinkedList<T>::ListDoublyLinkedList() {
    list = new DoublyLinkedList<T>();
}

template<typename T>
ListDoublyLinkedList<T>::~ListDoublyLinkedList() {
    delete list;
}

template<typename T>
ListDoublyLinkedList<T>::ListDoublyLinkedList(const ListDoublyLinkedList<T>& that) {
    list = new DoublyLinkedList<T>(*(that.list));
}

template<typename T>
ListDoublyLinkedList<T>& ListDoublyLinkedList<T>::operator=(const ListDoublyLinkedList<T>& that) {
    if (this == &that) {
        return *this;
    }

    delete list;
    list = new DoublyLinkedList<T>(*(that.list));
    return *this;
}

template<typename T>
bool ListDoublyLinkedList<T>::empty() {
    return list->size() == 0;
}

template<typename T>
int ListDoublyLinkedList<T>::size() {
    return list->size();
}

template<typename T>
void ListDoublyLinkedList<T>::clear() {
    delete list;
    list = new DoublyLinkedList<T>();
}

template<typename T>
typename ListDoublyLinkedList<T>::ListIterator ListDoublyLinkedList<T>::begin() {
    return ListIterator(this->list);
}

/////////////

template<typename T>
ListDoublyLinkedList<T>::ListIterator::ListIterator(DoublyLinkedList<T>* list) {
    this->list = list;
    current = list->pre->next;
    last = nullptr;
}

template<typename T>
ListDoublyLinkedList<T>::ListIterator::ListIterator(const ListIterator& that) {
    list = that.list;
    current = that.current;
    last = that.last;
}

template<typename T>
typename ListDoublyLinkedList<T>::ListIterator& ListDoublyLinkedList<T>::ListIterator::operator=(const ListIterator& that) {
    list = that.list;
    current = that.current;
    last = that.last;
}

template<typename T>
bool ListDoublyLinkedList<T>::ListIterator::has_next() const {
    return current != list->post;
}

template<typename T>
bool ListDoublyLinkedList<T>::ListIterator::has_previous() const {
    return current->prev != list->pre;
}

template<typename T>
T ListDoublyLinkedList<T>::ListIterator::next() {
    if (!has_next()) {
        throw CustomException("The iterator has no next element!");
    }

    typename DoublyLinkedList<T>::Node* next_node = current;
    current = current->next;
    last = next_node;
    return next_node->info;
}

template<typename T>
T ListDoublyLinkedList<T>::ListIterator::previous() {
    if (!has_previous()) {
        throw CustomException("The iterator has no previous element!");
    }

    current = current->prev;
    last = current;
    return current->info;
}

template<typename T>
void ListDoublyLinkedList<T>::ListIterator::add(T element) {
    list->add(element, current);
    last = nullptr;
}

template<typename T>
void ListDoublyLinkedList<T>::ListIterator::set(T element) {
    if (last == nullptr) {
        throw CustomException("Neither next or previous have been called!");
    }

    list->set(element, last);
}

template<typename T>
void ListDoublyLinkedList<T>::ListIterator::remove() {
    if (last == nullptr) {
        throw CustomException("Neither next or previous have been called!");
    }

    if (last == current) {
        current = current->next;
    }

    list->remove(last);
    last = nullptr;
}

#endif /* LISTDOUBLYLINKEDLIST_H_ */
