#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int n; // items
    int q; // queries
    cin>>n;
    cin>>q;

    vector<int> prices(n);
    // x = must buy x items, will get y cheapest items free

    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    sort(prices.begin(), prices.end());


    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + prices[i];
    }

    while (q--) {
        int x;
        int y;
        cin >> x;
        cin >> y;

        int start = n - x;
        int end = n - x + y;

        cout << prefix[end] - prefix[start] << endl;

    }

    return 0;
 	
}