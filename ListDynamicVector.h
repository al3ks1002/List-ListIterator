#include "ListIteratorDV.h"

template<typename T>
class ListDynamicVector {
    public:
        ListDynamicVector();
        ~ListDynamicVector();
        ListDynamicVector(const ListDynamicVector& that);
        ListDynamicVector& operator=(const ListDynamicVector& that);

        bool empty() const;
        int size() const;
        void clear();

        ListIteratorDV<T> begin();
        ListIteratorDV<T> end();

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
ListDynamicVector<T>::ListDynamicVector(const ListDynamicVector& that) {
    vector = new DynamicVector<T>(that);
}

template<typename T>
ListDynamicVector<T>& ListDynamicVector<T>::operator=(const ListDynamicVector& that) {
    if (this == &that)
        return *this;

    delete vector;
    vector = new DynamicVector<T>(that);
    return *this;
}

template<typename T>
bool ListDynamicVector<T>::empty() const {
    return vector.size() == 0;
}

template<typename T>
int ListDynamicVector<T>::size() const {
    return vector.size();
}

template<typename T>
void ListDynamicVector<T>::clear() {
    delete vector;
    vector = new DynamicVector<T>();
}

template<typename T>
ListIteratorDV<T> ListDynamicVector<T>::begin() {
    return ListIteratorDV<T>(this->vector, 0);
}

template<typename T>
ListIteratorDV<T> ListDynamicVector<T>::end() {
    return ListIteratorDV<T>(this->vector, vector->size());
}
