#include <bits/stdc++.h>

using namespace std;

const int NMAX = 50000;
const int VMAX = 1000000000;

int main() {
    freopen("test4.in", "w", stdout);
    srand(time(0));

    int n = NMAX;
    cout << n << '\n';
    for (int i = 1; i <= n; i++) {
        cout << rand() % VMAX << " ";
        cout << rand() % VMAX << " ";
        cout << rand() % VMAX << '\n';
    }

    return 0;
}
