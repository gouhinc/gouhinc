#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

void solve()
{
    long n,x;
    cin >> n; // piles
    cin >> x; // max diff

    int cnt = 0;
    long long low = 0;
    long long high = LLONG_MAX;

    vector<long long> piles(n); // piles of food

    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }
    
    for (int i = 0; i < n; i++) {
        long long left = piles[i] - x;
        long long right = piles[i] + x;

        low = max(low, left);
        high = min(high, right);

        if (low > high) {
            cnt++;
            low = left;
            high = right;
        }

    }

    cout << cnt << endl;

    return;
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