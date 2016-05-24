#include "ListException.h"

template<typename T>
class ListDynamicVector {
    public:
        class ListIterator {
            public:
                ListIterator(ListDynamicVector* list, int index) :
                    list(list), current_index(index), last_index(-1) {}

                ~ListIterator() {}

                ListIterator(const ListIterator& that) {
                    list = that.list;
                    current_index = that.current_index;
                    last_index = that.last_index;
                }

                ListIterator& operator=(const ListIterator& that) {
                    list = that.list;
                    current_index = that.current_index;
                    last_index = that.last_index;
                }

                bool has_next() {
                    return current_index < list->dimension;
                }

                bool has_previous() {
                    return current_index > 0;
                }

                T next() {
                    if (current_index + 1 > list->dimension) {
                        throw ListException("The iterator has no next element!");
                    }

                    last_index = current_index;
                    return list->elements[current_index++];
                }

                T previous() {
                    if (current_index - 1 < 0) {
                        throw ListException("The iterator has no previous element!");
                    }

                    last_index = current_index - 1;
                    return list->elements[--current_index];
                }

                int next_index() {
                    return current_index;
                }

                int previous_index() {
                    return current_index - 1;
                }

                void add(T element) {
                    if (list->dimension == list->capacity) {
                        resize();
                    }

                    list->dimension++;
                    for (int i = list->dimension; i > current_index; i--) {
                        list->elements[i] = list->elements[i - 1];
                    }

                    list->elements[current_index] = element;
                    last_index = -1;
                }

                void set(T element) {
                    if (last_index == -1) {
                        throw ListException("Neither next or previous have been called!");
                    }

                    list->elements[last_index] = element;
                }

                void remove() {
                    if (last_index == -1) {
                        throw ListException("Neither next or previous have been called!");
                    }

                    list->dimension--;
                    for (int i = last_index; i < list->dimension; i++) {
                        list->elements[i] = list->elements[i + 1];
                    }

                    last_index = -1;
                }

            private:
                ListDynamicVector* list;
                int current_index;
                int last_index;

                void resize() {
                    list->capacity *= 2;

                    T* aux = new T[list->capacity];
                    for (int i = 0; i < list->dimension; i++) {
                        aux[i] = list->elements[i];
                    }

                    delete[] list->elements;
                    list->elements = aux;
                }
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

            for (int i = 0; i < dimension; i++) {
                elements[i] = elements.that[i];
            }
        }

        ListDynamicVector& operator=(const ListDynamicVector& that) {
            if (this == &that)
                return *this;

            dimension = that.dimension;
            capacity = that.capacity;

            delete[] elements;
            elements = new T[capacity];

            for (int i = 0; i < dimension; i++) {
                elements[i] = elements.that[i];
            }

            return *this;
        }

        bool empty() const {
            return dimension == 0;
        }

        int size() const {
            return dimension;
        }

        void clear() {
            dimension = 0;
        }

        ListIterator begin() {
            return ListIterator(this, 0);
        }

        ListIterator end() {
            return ListIterator(this, dimension);
        }

        ListIterator iterator(int index) {
            return ListException(this, index);
        }

        T& operator[] (int index) {
            if (index < 0 || index >= dimension) {
                throw ListException("Index out of range!");
            }

            return elements[index];
        }

    private:
        int capacity;
        int dimension;
        T* elements;
};
