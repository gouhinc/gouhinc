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
   string s;
   cin >> s;

   vector<int> lower;
   vector<int> upper;
   vector<bool> keep(s.size(), true);

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'b') {
            keep[i] = false;
            if (!lower.empty()) {
                keep[lower.back()] = false;
                lower.pop_back();
            }
        } else if (s[i] == 'B') {
            keep[i] = false;
            if (!upper.empty()) {
                keep[upper.back()] = false;
                upper.pop_back();
            }
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            lower.push_back(i);
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            upper.push_back(i);
        }
    }

    for (int i = 0; i < s.size(); i++) {
        if (keep[i]) cout << s[i];
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