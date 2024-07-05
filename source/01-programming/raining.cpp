
//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <stack>


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


    int t;
    cin >> t;

    while(t>0) {
        string str;
        cin >> str;

        stack<int> s;
        int volume = 0;

        rep(i,str.length()) {
            if(str[i] == '\\') {
                s.push(i);
            }else if(str[i] == '/') {
                if(!s.empty()) {
                    volume += i - s.top();
                    s.pop();
                }
            }
        }

        cout << volume << endl;
        t--;
    }

    return 0;
}

