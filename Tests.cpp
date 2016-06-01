#include "ListDynamicVector.h"
#include "ListDoublyLinkedList.h"

#include <iostream>
#include <cassert>

using namespace std;

void test_vector() {
    DynamicVector<int> v1;
    for (int i = 0; i < 5; i++) {
        v1.add(i * 10, i);
    }

    assert(v1.size() == 5);
    for (int i = 0; i < 5; i++) {
        assert(v1[i] == i * 10);
    }

    v1.remove(2);
    assert(v1.size() == 4);
    assert(v1[2] == 30);

    try {
        v1[4] = 0;
        assert(false);
    } catch (CustomException e) {}

    try {
        v1[-1] = 0;
        assert(false);
    } catch (CustomException e) {}

    v1.add(100, 4);
    try {
        v1.add(200, 6);
        assert(false);
    } catch (CustomException e) {}

    try {
        v1.remove(5);
        assert(false);
    } catch (CustomException e) {}

    v1.set(200, 4);
    try {
        v1.set(200, 5);
        assert(false);
    } catch (CustomException e) {}

    DynamicVector<int> v2(v1);
    assert(v1.size() == v2.size());
    for (int i = 0; i < v1.size(); i++)
        assert(v2[i] == v1[i]);

    v1.remove(0);
    DynamicVector<int> v3;
    v3 = v2 = v1;

    assert(v3.size() == v2.size());
    assert(v3.size() == v1.size());
    for (int i = 0; i < v1.size(); i++) {
        assert(v2[i] == v1[i]);
        assert(v3[i] == v1[i]);
    }

    v1.clear();
    assert(v1.size() == 0);
    v1.add(2, 0);
    assert(v1[0] == 2);
}

void test_listDV() {
    ListDynamicVector<int> l1;
    assert(l1.size() == 0);

    ListDynamicVector<int>::ListIterator it = l1.begin();
    it.add(1);
    it.add(2);
    it.add(3);
    assert(l1.size() == 3);
    assert(l1.empty() == 0);

    ListDynamicVector<int> l2(l1);
    assert(l1.size() == 3);
    it = l2.begin();
    assert(it.next() == 1);
    it.remove();

    ListDynamicVector<int> l3;
    l3 = l1 = l2;
    assert(l3.size() == 2);
    assert(l1.size() == 2);

    l3.clear();
    assert(l3.size() == 0);
    assert(l3.empty() == 1);

    it = l1.begin();
    it.add(1);
    assert(it.next() == 2);
    assert(it.next() == 3);
    try {
        it.next();
        assert(false);
    } catch (CustomException e) {}

    assert(it.previous() == 3);
    assert(it.previous() == 2);
    assert(it.previous() == 1);
    try {
        it.previous();
        assert(false);
    } catch (CustomException e) {}

    it.next();
    it.next();
    it.remove();
    try {
        it.remove();
        assert(false);
    } catch (CustomException e) {}

    assert(it.next() == 3);
    assert(it.previous() == 3);
    assert(it.previous() == 1);

    it = l1.begin();
    it.next();
    it.next();
    assert(it.has_previous() == 1);
    assert(it.has_next() == 0);
    assert(it.previous() == 3);
    it.add(2);
    try {
        it.remove();
        assert(false);
    } catch (CustomException e) {}

    assert(it.next() == 3);
    assert(it.previous() == 3);
    assert(it.previous() == 2);
    assert(it.previous() == 1);
    assert(it.has_previous() == 0);
    it.remove();
    assert(it.has_previous() == 0);
    assert(it.has_next() == 1);
    assert(it.next() == 2);
    it.set(5);
    assert(it.previous() == 5);
    it.next();
    it.next();
    it.remove();
    assert(it.has_next() == 0);
    assert(it.has_previous() == 1);
    assert(it.previous() == 5);
    it.remove();
    assert(it.has_next() == 0);
    assert(it.has_previous() == 0);

    it.add(1);
    it.add(2);
    it.add(3);

    ListDynamicVector<int>::ListIterator it2(it);
    ListDynamicVector<int>::ListIterator it3;
    it3 = it;
    assert(it3.has_next() == 0);
    assert(it2.has_next() == 0);
    assert(it3.previous() == 3);
    assert(it2.previous() == 3);

    ListDynamicVector<int> list;
    it = list.begin();
    it.add(24);
    it.add(65);
    it.add(2);
    it.add(39);
    it.add(86);
    it.add(24);
    it.add(50);
    it.add(47);
    it.add(13);
    it.add(4);

    it = list.begin();
    while (it.has_next()) {
        int x = it.next();
        it.set(x + 1);
    }

    while (it.has_previous()) {
        int x = it.previous();
        it.set(3 * x);
    }

    while (it.has_next()) {
        int x = it.next();
        if (x % 4 == 0) {
            it.remove();
        }
    }

    /* it = list.begin(); */
    /* while (it.has_next()) { */
    /*     cerr << it.next() << " "; */
    /* } */
}

void test_listDLL() {
    ListDoublyLinkedList<int> l1;
    assert(l1.size() == 0);

    ListDoublyLinkedList<int>::ListIterator it = l1.begin();
    it.add(1);
    it.add(2);
    it.add(3);
    assert(l1.size() == 3);
    assert(l1.empty() == 0);

    ListDoublyLinkedList<int> l2(l1);
    assert(l1.size() == 3);
    it = l2.begin();
    assert(it.next() == 1);
    it.remove();

    ListDoublyLinkedList<int> l3;
    l3 = l1 = l2;
    assert(l3.size() == 2);
    assert(l1.size() == 2);

    l3.clear();
    assert(l3.size() == 0);
    assert(l3.empty() == 1);

    it = l1.begin();
    it.add(1);
    assert(it.next() == 2);
    assert(it.next() == 3);
    try {
        it.next();
        assert(false);
    } catch (CustomException e) {}

    assert(it.previous() == 3);
    assert(it.previous() == 2);
    assert(it.previous() == 1);
    try {
        it.previous();
        assert(false);
    } catch (CustomException e) {}

    it.next();
    it.next();
    it.remove();
    try {
        it.remove();
        assert(false);
    } catch (CustomException e) {}

    assert(it.next() == 3);
    assert(it.previous() == 3);
    assert(it.previous() == 1);

    it = l1.begin();
    it.next();
    it.next();
    assert(it.has_previous() == 1);
    assert(it.has_next() == 0);
    assert(it.previous() == 3);
    it.add(2);
    try {
        it.remove();
        assert(false);
    } catch (CustomException e) {}

    assert(it.next() == 3);
    assert(it.previous() == 3);
    assert(it.previous() == 2);
    assert(it.previous() == 1);
    assert(it.has_previous() == 0);
    it.remove();
    assert(it.has_previous() == 0);
    assert(it.has_next() == 1);
    assert(it.next() == 2);
    it.set(5);
    assert(it.previous() == 5);
    it.next();
    it.next();
    it.remove();
    assert(it.has_next() == 0);
    assert(it.has_previous() == 1);
    assert(it.previous() == 5);
    it.remove();
    assert(it.has_next() == 0);
    assert(it.has_previous() == 0);

    it.add(1);
    it.add(2);
    it.add(3);

    ListDoublyLinkedList<int>::ListIterator it2(it);
    ListDoublyLinkedList<int>::ListIterator it3;
    it3 = it;
    assert(it3.has_next() == 0);
    assert(it2.has_next() == 0);
    assert(it3.previous() == 3);
    assert(it2.previous() == 3);

    ListDoublyLinkedList<int> list;
    it = list.begin();
    it.add(24);
    it.add(65);
    it.add(2);
    it.add(39);
    it.add(86);
    it.add(24);
    it.add(50);
    it.add(47);
    it.add(13);
    it.add(4);

    it = list.begin();
    while (it.has_next()) {
        int x = it.next();
        it.set(x + 1);
    }

    while (it.has_previous()) {
        int x = it.previous();
        it.set(3 * x);
    }

    while (it.has_next()) {
        int x = it.next();
        if (x % 4 == 0) {
            it.remove();
        }
    }

    /* it = list.begin(); */
    /* while (it.has_next()) { */
    /*     cerr << it.next() << " "; */
    /* } */
}

int main() {
    test_vector();
    test_listDV();
    test_listDLL();

    return 0;
}
