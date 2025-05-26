#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector<vector<pair<int, pair<long long, long long>>>> adj;
vector<long long> temp;
vector<int> ans;

void solve()
{
    long n;
    char d;
    cin >> n;
    cin >> d;

    string s;
    cin >> s;

    bool insert = false;

    for (long i = 0; i < s.size(); i++) {
        if (!insert && s[i] < d) {
            cout << d;
            insert = true;
        }
        cout << s[i];
    }

    if (!insert) {
        cout << d;
    }

    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}