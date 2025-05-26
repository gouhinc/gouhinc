#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int solve() {
    int n;
    int m;
    cin >> n;
    cin >> m;

    vector <long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> prefixMax(n);
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];
        prefixMax[i] = max((i ? prefixMax[i - 1] : 0LL), sum);
    }

    while (m--) {
        long long x;
        cin >> x;

        if (prefixMax.back() >= x) {
            auto it = lower_bound(prefixMax.begin(), prefixMax.end(), x);
            cout << it - prefixMax.begin() << " ";
        } else {
            if (sum <= 0) {
                cout << -1 << " ";
            } else {
                long long rounds = (x - prefixMax.back() + sum - 1) / sum;
                long long remaining = x - rounds * sum;
                auto it = lower_bound(prefixMax.begin(), prefixMax.end(), remaining);
                cout << rounds * n + (it - prefixMax.begin()) << " ";
            }
        }
    }
    cout << '\n';
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}