#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

void solve()
{

    long a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    long x = a + b + c;

    if (x % 2 != 0)
    {
        cout << -1 << endl;
        return;
    }

    long ans = min(x / 2, (a + b));
    cout << ans << endl;
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