#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int solve()
{
    int n;
    string s[2];
    string ans = "YES";

    cin >> n;

    for (int i = 0; i < 2; i++) {
        cin >> s[i];
    }

    for (int i = 1; i < n; i++) {
        if (s[0][i] == '1' && s[1][i] == '1') {
            ans = "NO";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}