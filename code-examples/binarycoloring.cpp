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
    int n;
    cin >> n;
    vector<long> mocha;
    string ans = "Yes";

    for (int x = 0; x < n; x++)
    {
        long y;
        cin >> y;

        mocha.push_back(y);
    }

    sort(mocha.begin(), mocha.end()); // optimize for run time

    int i = mocha[0];
    int j

    for (int x = 1; x < n; x++) {
        
    }



    /*
    cout << "Vector elements: ";
    for (const auto &element : mocha)
    {
        cout << element << " ";
    }
    cout << endl;*/
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