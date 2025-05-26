#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    vector<vector<int>> pos(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].emplace_back(i);
    }

    vector<int> ans(n + 10, -1);

    for (int i = 1; i <= n; i++) {
        int sz = static_cast<int>(pos[i].size());
        if (sz == 0) continue;

        int max_gap = pos[i][0] + 1;  // first occurrence contributes gap from start

        for (int j = 0; j < sz - 1; j++) {
            max_gap = max(max_gap, pos[i][j + 1] - pos[i][j]);
        }

        max_gap = max(max_gap, n - pos[i][sz - 1]);  // from last occurrence to end

        if (ans[max_gap] == -1) {
            ans[max_gap] = i;
        } else {
            ans[max_gap] = min(ans[max_gap], i);
        }
    }

    int min_value = numeric_limits<int>::max();

    for (int i = 1; i <= n; i++) {
        if (ans[i] != -1) {
            min_value = min(min_value, ans[i]);
        }

        if (min_value != numeric_limits<int>::max()) {
            ans[i] = min_value;
        }

        cout << ans[i] << " ";
    }

    cout << "\n";
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