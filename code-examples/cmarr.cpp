#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

bool allx(int x, const vector<int>& a) {
    int n = a.size();

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j<= i+2 && j < n; j++) {
            if (a[i] >= x && a[j] >= x) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int x;
    cin >> x;
    while (x--) {
        int n;
        cin >> n;
    
        vector<int> ints(n);
    
        for (int i = 0; i < n; i++) {
            cin >> ints[i];
        }
    
        int low = 1;
        int high = *max_element(ints.begin(), ints.end());
        int ans = -1;
    
        while (low <= high) {
            int mid = (low + high) / 2;
    
            if (allx(mid, ints)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}