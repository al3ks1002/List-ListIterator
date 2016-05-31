#include "DynamicVector.h"

#include <cstdio>

template<typename T>
class ListIteratorDV {
    public:
        ListIteratorDV() {}
        ~ListIteratorDV() {}
        ListIteratorDV(DynamicVector<T>* vector, int index);
        ListIteratorDV(const ListIteratorDV& that);
        ListIteratorDV& operator=(const ListIteratorDV& that);

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
        DynamicVector<T>* vector;
        int current_index;
        int last_index;
};

template<typename T>
ListIteratorDV<T>::ListIteratorDV(DynamicVector<T>* vector, int index) {
    this->vector = vector;
    current_index = index;
    last_index = -1;
}

template<typename T>
ListIteratorDV<T>::ListIteratorDV(const ListIteratorDV& that) {
    vector = that.vector;
    current_index = that.current_index;
    last_index = that.last_index;
}

template<typename T>
ListIteratorDV<T>& ListIteratorDV<T>::operator=(const ListIteratorDV& that) {
    vector = that.vector;
    current_index = that.current_index;
    last_index = that.last_index;
}

template<typename T>
bool ListIteratorDV<T>::has_next() const {
    return current_index < vector->size();
}

template<typename T>
bool ListIteratorDV<T>::has_previous() const {
    return current_index > 0;
}

template<typename T>
T ListIteratorDV<T>::next() {
    if (!has_next()) {
        throw CustomException("The iterator has no next element!");
    }

    last_index = current_index;
    return (*vector)[current_index++];
}

template<typename T>
T ListIteratorDV<T>::previous() {
    if (!has_previous()) {
        throw CustomException("The iterator has no previous element!");
    }

    last_index = current_index - 1;
    return (*vector)[--current_index];
}

template<typename T>
int ListIteratorDV<T>::next_index() const {
    return current_index;
}

template<typename T>
int ListIteratorDV<T>::previous_index() const {
    return current_index - 1;
}

template<typename T>
void ListIteratorDV<T>::add(T element) {
    vector->add(element, current_index);
    current_index++;
    last_index = -1;
}

template<typename T>
void ListIteratorDV<T>::set(T element) {
    if (last_index == -1) {
        throw CustomException("Neither next or previous have been called!");
    }

    vector->set(element, last_index);
}

template<typename T>
void ListIteratorDV<T>::remove() {
    if (last_index == -1) {
        throw CustomException("Neither next or previous have been called!");
    }

    vector->remove(last_index);
    if (last_index != current_index) {
        current_index--;
    }

    last_index = -1;
}
