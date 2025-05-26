#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> gang(n);
    for (int i = 0; i < n; i++) {
        cin >> gang[i];
    }

    int first_diff = -1;
    for (int i = 1; i < n; i++) {
        if (gang[i] != gang[0]) {
            first_diff = i;
            break;
        }
    }

    if (first_diff == -1) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    for (int i = 1; i < n; i++) {
        if (gang[i] != gang[0]) {
            cout << 1 << " " << (i + 1) << endl;
        }
    }

    for (int i = 1; i < n; i++) {
        if (gang[i] == gang[0]) {
            cout << (i + 1) << " " << (first_diff + 1) << endl;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}