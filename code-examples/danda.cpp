#include <vector>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void solve()
{
    int n;
    int k;

    cin >> n;
    cin >> k;

    if (n < k) {
        cout << k - n << endl;
    } else {
        cout << ((n - k) % 2) << endl;
    }
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