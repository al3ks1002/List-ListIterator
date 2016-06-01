#ifndef DYNAMICVECTOR_H_
#define DYNAMICVECTOR_H_

#include "CustomException.h"

template<typename T>
class DynamicVector {
    public:
        DynamicVector();
        ~DynamicVector();
        DynamicVector(const DynamicVector<T>& that);
        DynamicVector& operator=(const DynamicVector<T>& that);

        int size() const;
        void add(T element, int index);
        void set(T element, int index);
        void remove(int index);
        void clear();
        T& operator[] (int index);

    private:
        int capacity;
        int dimension;
        T* elements;

        void resize();
};

template<typename T>
DynamicVector<T>::DynamicVector() {
    dimension = 0;
    capacity = 2;
    elements = new T[2];
}

template<typename T>
DynamicVector<T>::~DynamicVector() {
    delete[] elements;
}

template<typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& that) {
    dimension = that.dimension;
    capacity = that.capacity;
    elements = new T[capacity];

    for (int i = 0; i < dimension; i++) {
        elements[i] = that.elements[i];
    }
}

template<typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& that) {
    if (this == &that)
        return *this;

    dimension = that.dimension;
    capacity = that.capacity;

    delete[] elements;
    elements = new T[capacity];

    for (int i = 0; i < dimension; i++) {
        elements[i] = that.elements[i];
    }

    return *this;
}

template<typename T>
int DynamicVector<T>::size() const {
    return dimension;
}

template<typename T>
void DynamicVector<T>::add(T element, int index) {
    if (index < 0 || index > dimension)
        throw CustomException("Index out of range!");

    if (dimension == capacity) {
        resize();
    }

    for (int i = dimension; i > index; i--) {
        elements[i] = elements[i - 1];
    }

    dimension++;
    elements[index] = element;
}

template<typename T>
void DynamicVector<T>::set(T element, int index) {
    if (index < 0 || index >= dimension)
        throw CustomException("Index out of range!");

    elements[index] = element;
}

template<typename T>
void DynamicVector<T>::remove(int index) {
    if (index < 0 || index >= dimension)
        throw CustomException("Index out of range!");

    dimension--;
    for (int i = index; i < dimension; i++) {
        elements[i] = elements[i + 1];
    }
}

template<typename T>
void DynamicVector<T>::clear() {
    delete[] elements;
    dimension = 0;
    capacity = 2;
    elements = new T[2];
}

template<typename T>
T& DynamicVector<T>::operator[] (int index) {
    if (index < 0 || index >= dimension) {
        throw CustomException("Index out of range!");
    }

    return elements[index];
}

template<typename T>
void DynamicVector<T>::resize() {
    capacity *= 2;

    T* aux = new T[capacity];
    for (int i = 0; i < dimension; i++) {
        aux[i] = elements[i];
    }

    delete[] elements;
    elements = aux;
}

#endif /* DYNAMICVECTOR_H_ */
