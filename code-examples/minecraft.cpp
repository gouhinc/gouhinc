#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int n;
    int m;
    cin>>n;
    cin>>m;
    
    vector<long long> cols(n);
    vector<long long> forward(n, 0);
    vector<long long> backward(n, 0);


    for (int i = 0; i < n; i++) {
        cin >> cols[i];
    }
    
    for (int i = 1; i < n; i++) {
        forward[i] = forward[i-1];
        if (cols[i] < cols[i-1]) {
            forward[i] += cols[i - 1] - cols[i];
        }
    }
    
    for (int i = n - 2; i >= 0; i--) {
        backward[i] = backward[i+1];
        if (cols[i] < cols[i+1]) {
            backward[i] += cols[i+1] - cols[i];
        }
    }

    while (m--) {
        int start;
        int end;
        cin >> start;
        cin >> end;
        start--;
        end--;
        if (start < end) {
            cout << forward[end] - forward[start] << endl;
        } else {
            cout << backward[end] - backward[start] << endl;
        }
    }

    return 0;
 	
}