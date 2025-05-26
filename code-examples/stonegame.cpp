#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int solve()
{
    int n;
    int a(n);

    cin >> n;

    for (int i = 0; i < 2; i++) {
        cin >> a[i];
    }

    int maxValue = INT_MAX;
    int minValue = INT_MIN;
    int minIndx = -1;
    int maxIndx = -1;

    for (int i = 0; i < n - 1; i++) {
        if (a[i] < minValue) {
            minValue = a[i];
            minIndx = i;
        }

        if (a[i] > maxValue) {
            maxValue = a[i];
            maxIndx = i;
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