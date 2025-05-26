#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

void solve()
{
    double x, y, ans;
    cin >> x; // 1x1
    cin >> y; // 2x2
    
    ans = ceil(y/2); // large/2 as estimate for how many screens
    
    while((ans * 15) - (y * 4) < x){ // total cells - cells w/ large = remaining room
        ans++;
    }
    
    cout << ans << endl;

    return;
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