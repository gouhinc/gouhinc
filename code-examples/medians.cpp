#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve()
{
    long long n, x;
    cin >> n;
    vector<pair<long long, long long>> vp;
    for (int i = 0; i < n; i++) {
        cin >> x;
        vp.push_back({x, 0});
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        vp[i].second = x;
    }
    sort(all(vp));
    vector<long long> up, down;
    vector<long long> suffix(n + 1, 0);
    fx(vp) {
        up.push_back(x.first);
        down.push_back(x.second);
    }
    for (int i = n - 1; i >= 0; i--) {
        suffix[i] = down[i] + suffix[i + 1];
    }
    long long ans = suffix[0];
    for (int i = 0; i < n; i++) {
        long long temp = max(up[i], suffix[i + 1]);
        ans = min(ans, temp);
    }
    cout << ans << "\n";
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