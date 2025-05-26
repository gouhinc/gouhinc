#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector<vector<pair<int, pair<long long, long long>>>> adj;
vector<long long> temp;
vector<int> ans;

int main()
{
    int max = 505;
    long long graph[max][max];
    int deleteOrder[max];
    bool isActive[max];
    long long result[max];
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
        }
    }

    for (int i = n; i >= 1; i--) {
        cin >> deleteOrder[i];
    }

    for (int i = 1; i <= n; i++) {
        isActive[i] = false;
    }

    for (int step = 1; step <= n; step++) {
        int k = deleteOrder[step];
        isActive[k] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }

        long long total = 0;
        for (int i = 1; i <= n; i++) {
            if (isActive[i]) {
                for (int j = 1; j <= n; j++) {
                    if (isActive[j]) {
                        total += graph[i][j];
                    }
                }
            }
        }

        result[step] = total;
    }
    for (int i = n; i >= 1; i--) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}