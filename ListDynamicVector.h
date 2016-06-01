#include "DynamicVector.h"

template<typename T>
class ListDynamicVector {
    public:
        class ListIterator {
            public:
                ListIterator() {}
                ~ListIterator() {}
                ListIterator(DynamicVector<T>* vector);
                ListIterator(const ListIterator& that);
                ListIterator& operator=(const ListIterator& that);

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

        ListDynamicVector();
        ~ListDynamicVector();
        ListDynamicVector(const ListDynamicVector<T>& that);
        ListDynamicVector& operator=(const ListDynamicVector<T>& that);

        bool empty() const;
        int size() const;
        void clear();

        ListIterator begin();

    private:
        DynamicVector<T>* vector;
};

template<typename T>
ListDynamicVector<T>::ListDynamicVector() {
    vector = new DynamicVector<T>();
}

template<typename T>
ListDynamicVector<T>::~ListDynamicVector() {
    delete vector;
}

template<typename T>
ListDynamicVector<T>::ListDynamicVector(const ListDynamicVector<T>& that) {
    vector = new DynamicVector<T>(*(that.vector));
}

template<typename T>
ListDynamicVector<T>& ListDynamicVector<T>::operator=(const ListDynamicVector<T>& that) {
    if (this == &that)
        return *this;

    delete vector;
    vector = new DynamicVector<T>(*(that.vector));
    return *this;
}

template<typename T>
bool ListDynamicVector<T>::empty() const {
    return vector->size() == 0;
}

template<typename T>
int ListDynamicVector<T>::size() const {
    return vector->size();
}

template<typename T>
void ListDynamicVector<T>::clear() {
    delete vector;
    vector = new DynamicVector<T>();
}

template<typename T>
typename ListDynamicVector<T>::ListIterator ListDynamicVector<T>::begin() {
    return ListIterator(this->vector);
}

/////////////////////////////

template<typename T>
ListDynamicVector<T>::ListIterator::ListIterator(DynamicVector<T>* vector) {
    this->vector = vector;
    current_index = 0;
    last_index = -1;
}

template<typename T>
ListDynamicVector<T>::ListIterator::ListIterator(const ListIterator& that) {
    vector = that.vector;
    current_index = that.current_index;
    last_index = that.last_index;
}

template<typename T>
typename ListDynamicVector<T>::ListIterator& ListDynamicVector<T>::ListIterator::operator=(const ListIterator& that) {
    vector = that.vector;
    current_index = that.current_index;
    last_index = that.last_index;
}

template<typename T>
bool ListDynamicVector<T>::ListIterator::has_next() const {
    return current_index < vector->size();
}

template<typename T>
bool ListDynamicVector<T>::ListIterator::has_previous() const {
    return current_index > 0;
}

template<typename T>
T ListDynamicVector<T>::ListIterator::next() {
    if (!has_next()) {
        throw CustomException("The iterator has no next element!");
    }

    last_index = current_index;
    return (*vector)[current_index++];
}

template<typename T>
T ListDynamicVector<T>::ListIterator::previous() {
    if (!has_previous()) {
        throw CustomException("The iterator has no previous element!");
    }

    last_index = current_index - 1;
    return (*vector)[--current_index];
}

template<typename T>
int ListDynamicVector<T>::ListIterator::next_index() const {
    return current_index;
}

template<typename T>
int ListDynamicVector<T>::ListIterator::previous_index() const {
    return current_index - 1;
}

template<typename T>
void ListDynamicVector<T>::ListIterator::add(T element) {
    vector->add(element, current_index);
    current_index++;
    last_index = -1;
}

template<typename T>
void ListDynamicVector<T>::ListIterator::set(T element) {
    if (last_index == -1) {
        throw CustomException("Neither next or previous have been called!");
    }

    vector->set(element, last_index);
}

template<typename T>
void ListDynamicVector<T>::ListIterator::remove() {
    if (last_index == -1) {
        throw CustomException("Neither next or previous have been called!");
    }

    vector->remove(last_index);
    if (last_index != current_index) {
        current_index--;
    }

    last_index = -1;
}
