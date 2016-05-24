#include "ListException.h"

template<typename T>
class ListDynamicVector {
    public:
        class ListIterator {
            public:
                ListIterator(ListDynamicVector& list) : list(list), current_index(0), last_index(-1) {}

                bool has_next() {
                    return current_index < list.dimension;
                }

                bool has_previous() {
                    return current_index > 0;
                }

                T next() {
                    if (current_index + 1 > list.dimension) {
                        throw ListException("The iterator has no next element!");
                    }

                    last_index = current_index;
                    return list[current_index++];
                }

                T previous() {
                    if (current_index - 1 < 0) {
                        throw ListException("The iterator has no previous element!");
                    }

                    last_index = current_index - 1;
                    return list[--current_index];
                }

                int next_index() {
                    return current_index;
                }

                int previous_index() {
                    return current_index - 1;
                }

                void set(T element) {
                    if (last_index == -1) {
                        throw ListException("Neither next or previous have been called, or remove or add have been called after the last call to next or previous!");
                    }

                    list[last_index] = element;
                }

                void add(T element) {
                    list.dimension++;
                    for (int i = list.dimension; i > current_index; i--)
                        list[i] = list[i - 1];

                    list[current_index] = element;
                    last_index = -1;
                }

                void remove() {
                    if (last_index == -1) {
                        throw ListException("Neither next or previous have been called, or remove or add have been called after the last call to next or previous!");
                    }

                    list.dimension--;
                    for (int i = last_index; i < list.dimension; i++)
                        list[i] = list[i + 1];

                    last_index = -1;
                }

            private:
                ListDynamicVector& list;
                int current_index;
                int last_index;
        };

    public:
        ListDynamicVector() {
            dimension = 0;
            capacity = 2;
            elements = new T[2];
        }

        ~ListDynamicVector() {
            delete[] elements;
        }

        ListDynamicVector(const ListDynamicVector& that) {
            dimension = that.dimension;
            capacity = that.capacity;
            elements = new T[capacity];

            for (int i = 0; i < dimension; i++)
                elements[i] = elements.that[i];
        }

        ListDynamicVector& operator=(const ListDynamicVector& that) {
            if (this == &that)
                return *this;

            dimension = that.dimension;
            capacity = that.capacity;

            delete[] elements;
            elements = new T[capacity];

            for (int i = 0; i < dimension; i++)
                elements[i] = elements.that[i];

            return *this;
        }

        bool empty() const {
            return dimension == 0;
        }

        int size() const {
            return dimension;
        }

        /* void clear(); */

        ListIterator iterator() {
            return ListIterator(*this);
        }

        /* ListIterator iterator(int index); */

        T& operator[] (int index) {
            return elements[index];
        }

    private:
        int capacity;
        int dimension;
        T* elements;

};
