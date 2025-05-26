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
   int n;
   cin >> n;

   vector<int> arr(n);

   for (int i = 0; i < n; i++) {
    cin >> arr[i];
   }

    sort(arr.begin(), arr.end());

    int count = 0;
    int threshold = 2 * arr[0] - 1;

    for (int i = 0; i < n; i++) {
        count += (arr[i] - 1) / threshold;
    }

    cout << count << '\n';
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