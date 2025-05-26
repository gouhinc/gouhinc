#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int solve()
{
    string number;
    cin >> number;

    int n = number.length();
    int removals = n;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            char first = number[i];
            char second = number[j];

            int pair = (first - '0') * 10 + (second - '0');

            if (pair % 25 == 0) {
                int removed = (j - i - 1) + ( n - j - 1);

                if (removed < removals) {
                    removals = removed;
                }
            }
        }
    }

    cout << removals << endl;
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