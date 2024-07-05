
//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
#include <cmath>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    string s;
    getline(cin, s);

    vector<int> abc (26, 0);

    string output = "";

    for(char c : s) {
        if(abc[c - 'a'] == 0) {
            output += c;
            abc[c - 'a'] += 1;
        } else {
            int i = output.find(c);
            string s1 = output;
            s1.erase(i, 1);
            s1 += c;
            if(s1 > output) {  // vllt >=
                output = s1;
            }
        }
    }

    cout << output << endl;

    //TODO funktioniert noch nicht :/
    return 0;
}

