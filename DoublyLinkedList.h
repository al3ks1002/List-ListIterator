#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

#include "CustomException.h"

#include <iostream>
using namespace std;

template<typename T>
class DoublyLinkedList {
    public:
        struct Node {
            Node* prev;
            Node* next;
            T info;

            Node() {}
            Node(T info) : info(info) {}
        };

        DoublyLinkedList();
        ~DoublyLinkedList();
        DoublyLinkedList(const DoublyLinkedList<T>& that);
        DoublyLinkedList& operator=(const DoublyLinkedList<T>& that);

        int size() const;
        void add(T element, Node* current);
        void set(T element, Node* current);
        void remove(Node* current);

    public:
        Node* pre;
        Node* post;

    private:
        int dimension;
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    dimension = 0;
    pre = new Node();
    post = new Node();
    pre->prev = nullptr;
    pre->next = post;
    post->prev = pre;
    post->next = nullptr;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node* current = pre;
    while (current != nullptr) {
        Node* last = current;
        current = current->next;
        delete last;
    }
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& that) {
    dimension = 0;
    pre = new Node();
    post = new Node();
    pre->prev = nullptr;
    pre->next = post;
    post->prev = pre;
    post->next = nullptr;

    Node* current = post;
    Node* other = that.post;
    other = other->prev;

    while (other != that.pre) {
        add(other->info, current);
        current = current->prev;
        other = other->prev;
    }
}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& that) {
    if (this == &that) {
        return *this;
    }

    ~DoublyLinkedList();

    dimension = 0;
    pre = new Node();
    post = new Node();
    pre->next = post;
    post->prev = pre;

    Node* current = post;
    Node* other = that.post;
    other = other->prev;

    while (other != that.pre) {
        add(other->info, current);
        current = current->prev;
        other = other->prev;
    }
}

template<typename T>
int DoublyLinkedList<T>::size() const {
    return dimension;
}

template<typename T>
void DoublyLinkedList<T>::add(T element, Node* current) {
    Node* prev_node = current->prev;
    Node* new_node = new Node();

    prev_node->next = new_node;
    new_node->prev = prev_node;
    new_node->next = current;
    new_node->info = element;
    current->prev = new_node;

    dimension++;
}

template<typename T>
void DoublyLinkedList<T>::set(T element, Node* current) {
    current->info = element;
}

template<typename T>
void DoublyLinkedList<T>::remove(Node* current) {
    Node* prev_node = current->prev;
    Node* next_node = current->next;

    prev_node->next = next_node;
    next_node->prev = prev_node;
    delete current;

    dimension--;
}

#endif /* DOUBLYLINKEDLIST_H_ */
