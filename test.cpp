#include "ListDynamicVector.h"

#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(false);

    ListDynamicVector<int> v;
    ListDynamicVector<int>::ListIterator iter = v.begin();
    iter.add(1);
    iter.next();
    iter.add(2);
    iter.next();
    iter.add(3);

    ListDynamicVector<int>::ListIterator mlc = v.begin();
    mlc.next();
    mlc.next();
    /* mlc.remove(); */
    /* mlc.remove(); */
    mlc.set(15);
    mlc.next();
    mlc.previous();
    mlc.previous();
    mlc.previous();
    mlc.set(35);

    ListDynamicVector<int>::ListIterator c = v.begin();
    while (c.has_next()) {
        cout << c.next() << endl;
    }

    c = v.end();
    while (c.has_previous()) {
        cout << c.previous() << endl;
    }

    auto it = v.begin();
    for (int i = 0; i < 10; i++) {
        it.add(i);
    }

    return 0;
}
