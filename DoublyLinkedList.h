#include "CustomException.h"

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

        int size() const;

    private:
        int dimension;
        Node* pre;
        Node* post;
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    dimension = 0;
    pre = new Node();
    post = new Node();
    pre.next = post;
    post.prev = pre;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while (pre != nullptr) {
        Node* next_node = pre->next;
        delete pre;
        pre = next_node;
    }
}

template<typename T>
int DoublyLinkedList<T>::size() const {
    return dimension;
}
