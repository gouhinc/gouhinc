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
    int n;
    cin >> n;

    vector<int> colors(n);
    vector<int> indx;
    int mini = INT_MAX;

    for (int i = 0; i < n; i++) {
        cin >> colors[i];
        mini = min(mini, colors[i]);
    }

    for (int i = 0; i < n; i++) {
        if (colors[i] == mini) {
            indx.push_back(i);
        }
    }

    long long count = (long long)mini * n;
    int maxi = 0;

    for (int i = 1; i < indx.size(); i++) {
        maxi = max(maxi, indx[i] - indx[i-1] -1);
    }

    maxi = max(maxi, n - (indx.back() - indx[0] + 1));

    cout << count + maxi << endl;

    return 0;
}

