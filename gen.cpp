#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("big.in", "w", stdout);
    srand(time(0));

    int n = 1000;
    cout << n << '\n';
    for (int i = 1; i <= n; i++) {
        cout << rand() % 1000 << " ";
        cout << rand() % 1000 << " ";
        cout << rand() % 1000 << '\n';
    }

    return 0;
}
