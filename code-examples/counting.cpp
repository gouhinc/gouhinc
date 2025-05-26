#include <vector>
#include <iostream>
#include <limits.h>
#include <cmath>
using namespace std;


void solve()
{
    int n;
    cin >> n;

    long long ans = 1;
    int i;

    for(i = 1; i <= 4; i++) {
        ans *= n - 4 + i;
        ans /= i;
    }

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