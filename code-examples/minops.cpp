#include <vector>
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

void solve()
{
    int n,k;
    cin >> n;
    cin >> k;
    int count = 0;
    
    if(k==1) {
        cout << n << endl;
        return;
    }

    while (n>0) {
        count += n % k;
        n /= k;
    }
    cout << count << endl;
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