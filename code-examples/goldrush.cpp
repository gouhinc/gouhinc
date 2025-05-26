#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int solve()
{
    long long n;
    long long m;
    cin >> n;
    cin >> m;

    long long g = gcd(n,m);

    n /= g;
    m /= g;

    int div3 = 0;
    while (n % 3 == 0) {
        div3++;
        n /= 3;
    }

    int div2 = 0;
    while (m % 2 == 0) {
        div2++;
        m /= 2;
    }

    if (n == 1 && m == 1 && div2 <= div3) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

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