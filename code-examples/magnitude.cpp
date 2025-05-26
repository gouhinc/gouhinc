#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <cmath>

void solve() {

    //4
    //-1000000000 1000000000 1000000000 1000000000

    int n;
    cin>>n;
    vector<long long> a(n); //4, > {_,_,_,_}

    for(int i=0; i<n; i++){ cin >> a[i]; } //a = {-1,1,1,1}

    vector<long long> prefixSum(n); // prefix = {_,_,_,_}
    long long mini;
    mini = a[0];
    prefixSum[0] = a[0]; // mini = -1; {-1,_,_,_}


    /*cout<<"Results"<<endl;
    cout<<prefixSum[0]<<endl;
    cout<<mini<<endl; */

    for(int i = 1; i < n; i++){ // has to start at one or else out of bounds exception
        prefixSum[i] = prefixSum[i-1] + a[i]; // prefixSum[1] = prefixSum[0] + a[1] = -1 + 1 = 0
        mini = min(mini, prefixSum[i]); // mini = -1
    }

    // {-1, 0, 1, 2}

    /*std::cout << "PrefixSum elements: ";
    for (int i = 0; i < n; i++) {
        std::cout << prefixSum[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "A elements: ";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    cout<<mini<<endl; */

    if(mini < 0){
        cout<<prefixSum.back() + 2 * abs(mini)<<endl;;
    } else {
        cout<<prefixSum.back()<<endl;
    }
}

int main() {
    int x;
    cin>>x;

    while(x--) {
        solve();
    }

    return 0;
}