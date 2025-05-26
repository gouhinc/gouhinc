#include <vector>
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

bool isPrime(int num)
{
    if (num < 1)
        return false;
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void solve()
{
    int l;
    int r;
    cin >> l;
    cin >> r;

    int gap = INT_MAX;
    int count = 0;
    int current;
    vector<int> nums;
    vector<int> primes;

    for(int x = l; x <= r; x++) {
        nums.push_back(x);
    }
    
    /*for (const auto& num : nums) {
        cout << num << " ";
      }
    cout << endl;*/
    
    for(int num : nums) {
        if (isPrime(num)) {
            count++;
            primes.push_back(num);
        }
    }

    /*for (const auto& num : primes) {
        cout << num << " ";
      }
    cout << endl;*/

    if(count < 2) {
        cout << -1 << endl;
        return;
    }

    current = primes.back();
    primes.pop_back();

    for(int x = primes.size() - 1; x >= 0; x--) {
        //cout << current << " and " << primes.at(x) << endl;
        
        if((current - primes.back()) < gap) {
            gap = current - primes.back();
        }

        current = primes.back();
        primes.pop_back();
    }

    cout << gap << endl;
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