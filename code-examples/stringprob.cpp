#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main() {
    int alphabet = 26;
    int max = INT_MAX / 2;
    int dist[alphabet][alphabet];

    string s, t;
    int n;

    cin >> s >> t;
    cin >> n;

    for (int i = 0; i < alphabet; i++) {
        for (int j = 0; j < alphabet; j++) {
            dist[i][j] = max;
        }
    }

    for (int i = 0; i < alphabet; i++) {
        dist[i][i] = 0;
    }

    if (s.length() != t.length()) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        char from, to;
        int cost;
        cin >> from;
        cin >> to;
        cin >> cost;

        int u = from - 'a';
        int v = to - 'a';

        if (cost < dist[u][v]) {
            dist[u][v] = cost;
        }

    }

    for (int k = 0; k < alphabet; k++) {
        for (int i = 0; i < alphabet; i++) {
            for (int j = 0; j < alphabet; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int totalCost = 0;
    string result = "";
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == t[i]) {
            result += s[i];
            continue;
        }
        int a = s[i] - 'a';
        int b = t[i] - 'a';
        int minCost = max;
        char bestChar = '#';

        for (int j = 0; j < alphabet; j++) {
            int costA = dist[a][j];
            int costB = dist[b][j];

            if (costA < max && costB < max) {
                int combinedCost = costA + costB;
                if (combinedCost < minCost) {
                    minCost = combinedCost;
                    bestChar = 'a' + j;
                }
            }
        }
        
        if (minCost == max) {
            cout << -1 << endl;
            return 0;
        }

        totalCost += minCost;
        result += bestChar;
    }

    cout << totalCost << endl;
    cout << result << endl;

    return 0;
    
}