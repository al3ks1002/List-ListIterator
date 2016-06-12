#include "Balloon.h"

#include <iostream>
#include <list>

using namespace std;

const int INFINITY = 1 << 30;

int main() {
    freopen("big.in", "r", stdin);

    list<Balloon> balloons;
    list<Balloon> answer;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        balloons.emplace_back(x, y, r);
    }

    balloons.sort();
    int current_finish = -INFINITY;
    for (auto b : balloons) {
        if (b.get_start() > current_finish) {
            answer.emplace_back(b);
            current_finish = b.get_finish();
        }
    }

    cout << "The biggest number of balloons is: ";
    cout << answer.size() << '\n';
    for (auto b : answer) {
        cout << '\n';
        cout << "X coordinate: " << b.get_x() << '\n';
        cout << "Y coordinate: " << b.get_y() << '\n';
        cout << "Radius: " << b.get_radius() << '\n';
    }

    return 0;
}
