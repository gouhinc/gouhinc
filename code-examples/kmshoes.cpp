#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int main()
{
    int n; // rocks?
    cin >> n;
    vector<long long> costs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> costs[i];
    }

    vector<long long> sorted_costs = costs;
    sort(sorted_costs.begin(), sorted_costs.end());


    vector<long long> prefix(n + 1, 0);
    vector<long long> sorted_prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + costs[i];
        sorted_prefix[i + 1] = sorted_prefix[i] + sorted_costs[i];
    }

    int m; // questions
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int type;
        int l;
        int r;
        cin >> type;
        cin >> l;
        cin >> r;

        if(type == 1) {
            cout << prefix[r] - prefix[l - 1] << endl;
        } else {
            cout << sorted_prefix[r] - sorted_prefix[l - 1] << endl;
        }
    }


    return 0;
}