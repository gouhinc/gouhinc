#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve()
{
    int l1, r1;
    int l2, r2;

    cin >> l1;
    cin >> r1;
    cin >> l2;
    cin >> r2;

    if (r1 < l2 || l1 > r2) {
        cout << 1;
    } else {
        if (l1 == l2 && r1 == r2) cout << (min(r1, r2) - max(l1,l2));
        else if (l1 == l2 || r1 == r2) cout << (min(r1, r2) - max(l1,l2)) + 1;
        else cout << (min(r1, r2) - max(l1,l2)) + 2;
    }

    cout << endl;
}

int main()
{
    int x;
    cin >> x;

    while (x--)
    {
        solve();
    }

    return 0;
}