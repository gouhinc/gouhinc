#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

vector<vector<pair<int, pair<long long, long long>>>> adj;
vector<long long> temp;
vector<int> ans;

void dfs(int node, long long sumA)
{
    for (auto x : adj[node])
    {
        int child = x.first;
        long long a = x.second.first;
        long long b = x.second.second;

        long long newA = sumA + a;
        long long newB = temp.back() + b;
        temp.push_back(newB);

        int idx = lower_bound(temp.begin(), temp.end(), newA) - temp.begin();
        if (idx != temp.size() && temp[idx] == newA)
            idx++;
        ans[child] = idx - 1;

        dfs(child, newA);
        temp.pop_back();
    }
}

void solve()
{
    int n;
    cin >> n;

    adj.clear();
    adj.resize(n);
    ans.clear();
    ans.resize(n);
    temp.clear();

    for (int i = 1; i < n; i++)
    {
        int x;
        long long y;
        long long z;

        cin >> x;
        cin >> y;
        cin >> z;
        x--;
        adj[x].push_back({i, {y, z}});
    }

    temp.push_back(0);
    dfs(0, 0);

    for (int i = 1; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}