#include "ListIteratorDLL.h"

template<typename T>
class ListDoublyLinkedList {
    private:
        class ListIteratorDLL {
            public:
                ListIteratorDLL() {}
                ~ListIteratorDLL() {}
                ListIteratorDLL(DoublyLinkedList<T>* list);
                ListIteratorDLL(const ListIteratorDLL& that);
                ListIteratorDLL& operator=(const ListIteratorDLL& that);

                bool has_next() const;
                bool has_previous() const;
                T next();
                T previous();
                int next_index() const;
                int previous_index() const;

                void add(T element);
                void set(T element);
                void remove();

            private:
                DoublyLinkedList<T>* list;
                Node* current;
                Node* last;
        };

    public:
        ListDoublyLinkedList();
        ~ListDoublyLinkedList();
        ListDoublyLinkedList(const ListDoublyLinkedList<T>& that);
        ListDoublyLinkedList& operator=(const ListDoublyLinkedList<T>& that);

        bool empty();
        bool size();
        void clear();

        ListIteratorDLL<T> begin();

    private:
        DoublyLinkedList<T>* list;
};
