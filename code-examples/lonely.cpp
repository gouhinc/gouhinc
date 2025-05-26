#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <numeric>
using namespace std;

const int MAXINPUT = 1e6 + 1;

int main()
{
    vector<bool> lonely(MAXINPUT, true);

    for (int x = 1; x <= MAXINPUT; x++)
    {
        for (int y = x + 1; y < MAXINPUT; y++)
        {
            int g = gcd(x, y);
            int a = x / g;
            int b = y / g;

            if (a + b > 1 && a + 1 > b && b + 1 > a)
            {
                lonely[x] = false;
                lonely[y] = false;
            }
        }
    }

    vector<int> count(MAXINPUT);
    count[0] = 0;

    for (int i = 1; i < MAXINPUT; i++) {
        count[i] = count[i-1] + (lonely[i] ? 1 : 0);
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << count[n] << '\n';
    }
    return 0;
}