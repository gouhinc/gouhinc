#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <unordered_set>
using namespace std;

void solve() {
    int n;
    cin>>n;
 	vector<string> input(n);
    unordered_set<string> temp;

    for (int x = 0; x < n; x++) {
        cin >> input[x];
        temp.insert(input[x]);
    }

    for (string s : input) {
        bool flag = false;
        for (int x = 1; x < s.size(); x++) {
            string prefix = s.substr(0,x);
            string suffix = s.substr(x);

            if (temp.count(prefix) && temp.count(suffix)) {
                cout << "1";
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "0";
        }
    }

    cout << endl;
 	
}

int main() {
    int x;
    cin >> x;

    while (x--)
    {
        solve();
    }

    return 0;
}