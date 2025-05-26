#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void solve() {

    // 1 10 3 3 1 1 1 1 10 3 10 10 2

    int n, k;
    cin>>n>>k; // n = length, k = colors

    vector<int> temp(n);
    vector<int> ans(n);

    map<int, int> freq;
    map<int, vector<int>> ind;

    for(int i=0; i<n; i++){
        cin >> temp[i];

        ind[temp[i]].push_back(i);
        freq[temp[i]]++;

    }
    /*
    cout << "Indeces: ";
    for(int x = 0; x < n+1; x++) {
        for(int i : ind[x]) {
            cout << i << " ";
        }
    }
    cout << endl;

    cout<< "Frequences: ";
    for(int x = 0; x < n+1; x++) {
        cout << freq[x] << " ";
    }
    */

    int lessthank;
    int count;
    int value;

    for (const auto& pair : freq) {

        value = pair.first;
        count = pair.second;

        if(count >=k) {
            //paint em

            for (int x = 0; x < k; x++) {
                ans[ind[value][x]] = x+1;
            }

        } else {
            lessthank += count;
        }
        //cout << "Value " << value << " appears: " << count << endl;
    }

    cout << "Final color assignments: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;


    /*

    

    

    int newcount = count/k*k;
    int newcolor = 0;

    for (const auto& pair : freq) {

        value = pair.first;
        count = pair.second;

        if(count < k && newcount != 0) {
            for (int x = 0; x<ind[value].size(); x++) {
                if (newcount != 0){
                    ans[ind[value][x]] = (newcolor % k) + 1;
                    newcolor ++;
                    newcount --;
                }
                //cout << "Index is: " 
                break;
            }

            
        }
        
        //cout << "Value " << value << " appears " << count << " times." << endl;
    }

    cout<<"answer: ";
    for(int x = 0; x < n; x++) {
        cout<<ans[x];
    }
    cout<<endl;

    */

   /*cout << "Results:";
    cout<<n<<endl;
    cout<<k<<endl;*/ 
    
}

int main() {
    int x;
    cin>>x;

    while(x--) {
        solve();
    }

    return 0;
}