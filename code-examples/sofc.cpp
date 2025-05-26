#include <vector>
#include <iostream>
#include <string>
using namespace std;

bool alleq(string in) {
    for (char character : in) {
        if (character != '=') return false;
    }
    return true;
}

void solve()
{
    string input;
    int ls = 0;
    int gr = 0;
    getline(cin, input);
    bool eq = alleq(input);

    // cout << eq << " " << input << endl;
    
    for (char character : input) {
        if (character == '<') ls++;
        else if (character == '>') gr++;
        // cout << character << " " << cnt << endl;
    }

    if (eq) cout << '=' << endl;
    else if (ls > 0 && gr == 0) cout << '<' << endl;
    else if (gr > 0 && ls == 0) cout << '>' << endl;
    else cout << '?' << endl;

    // cout << input << endl;
    // >
    // ?
    // =
    //<

}

int main()
{
    int x;
    cin >> x;
    cin.ignore(); 

    while (x--)
    {
        solve();
    }

    return 0;
}