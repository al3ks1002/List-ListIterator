#include <bits/stdc++.h>

using namespace std;

struct balloon {
    int x, y, radius;
    int start, finish;

    balloon(int _x, int _y, int _radius) {
        x = _x;
        y = _y;
        radius = _radius;
        start = x - radius;
        finish = x + radius;
    }

    bool operator < (const balloon& that) const {
        return finish < that.finish;
    }
};

int main() {
    freopen("sda.in", "r", stdin);

    list<balloon> balloons;
    vector<balloon> answer;

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
        if (b.start > current_finish) {
            answer.emplace_back(b);
            current_finish = b.finish;
        }
    }

    cout << "The biggest number of balloons is: ";
    cout << answer.size() << '\n';
    for (auto b : answer) {
        cout << '\n';
        cout << "X coordinate: " << b.x << '\n';
        cout << "Y coordinate: " << b.y << '\n';
        cout << "Radius: " << b.radius << '\n';
    }

    return 0;
}
