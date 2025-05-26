#include <vector>
#include <iostream>
#include <climits>
#include <cmath>
#include <queue>
using namespace std;

void solve()
{
    int people,meet,connects;
    cin >> people;
    cin >> meet;
    cin >> connects;

    int verts = people + meet - 1;
    vector<vector<vector<int>>> adj(verts);

    for (int i = 0; i < connects; i++) {
        int u,v,wt;

        cin >> u;
        cin >> v;
        cin >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    vector<int> dist(verts, INT_MAX);

    pq.push({0, src});
    

    cout << people << endl;
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