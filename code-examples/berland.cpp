#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void update(vector<vector<int>>& dist, int a, int b, int c, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int new_dist = min(dist[i][a] + c + dist[b][j], dist[i][b] + c + dist[a][j]);
            if (dist[i][j] > new_dist) {
                dist[i][j] = new_dist;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> distance(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> distance[i][j];
        }
    }

    int k;
    cin >> k;

    for (int step = 0; step < k; step++) {
        int a;
        int b;
        int c;

        cin >> a;
        cin >> b;
        cin >> c;

        if (distance[a][b] > c) {
            distance[a][b] = c;
            distance[b][a] = c;
        }

        update(distance, a, b, c, n);

        long long total = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                total += distance[i][j];
            }
        }

        cout << total << " ";
    }

    cout << endl;
    return 0;
}