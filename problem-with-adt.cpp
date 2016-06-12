#include "Balloon.h"
#include "ListDoublyLinkedList.h"
#include "ListDynamicVector.h"

#include <iostream>

using namespace std;

const int INFINITY = 1 << 30;

void add_balloon(ListDoublyLinkedList<Balloon>& balloons, Balloon b) {
    auto it = balloons.begin();
    while (it.has_next()) {
        Balloon current = it.next();
        if (current.get_finish() > b.get_finish()) {
            it.previous();
            break;
        }
    }
    it.add(b);
}

int main() {
    freopen("big.in", "r", stdin);

    ListDoublyLinkedList<Balloon> balloons;
    ListDoublyLinkedList<Balloon> answer;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        Balloon b(x, y, r);
        add_balloon(balloons, b);
    }

    int current_finish = -INFINITY;
    auto answer_it = answer.begin();
    auto balloons_it = balloons.begin();
    while (balloons_it.has_next()) {
        Balloon b = balloons_it.next();
        if (b.get_start() > current_finish) {
            answer_it.add(b);
            current_finish = b.get_finish();
        }
    }

    cout << "The biggest number of balloons is: ";
    cout << answer.size() << '\n';
    answer_it = answer.begin();
    while (answer_it.has_next()) {
        Balloon b = answer_it.next();
        cout << '\n';
        cout << "X coordinate: " << b.get_x() << '\n';
        cout << "Y coordinate: " << b.get_y() << '\n';
        cout << "Radius: " << b.get_radius() << '\n';
    }

    return 0;
}
