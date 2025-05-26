#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int solve()
{
    int n,k;
    cin >> n;
    cin >> k;

    int count = 0;
    
    vector<int> v(n);

    for (auto &x : v) {
        cin >> x;
    }

    vector<int> temp =v;
    sort(temp.begin(), temp.end());

    map<int, set<int>> m;
    for (int i = 0; i < n; i++) {
        m[i % k].insert(v[i]);
    }

    map<int, int> m2;
    for (int i = 0; i < n; i++) {
        auto &check = m[i % k];
        if (check.find(temp[i]) == check.end()) {
            m2[i % k]++;
        }
    }

    if (m2.empty()) {
        cout << "0\n";
        return 0;
    }

    for (auto x : m2) {
        if (x.second == 1) {
            count++;
        } else {
            count += 100;
        }
    }

    if (count == 2) {
        cout << "1\n";
    } else {
        cout << "-1\n";
    }

    return 0;
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