
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


    ll t;
    cin >> t;
    rep(j,t) {
        ll n;
        cin >> n;
        string str;
        cin >> str;

        ll b = 0, w = 0;

        rep(i,n) {
            if(str[i]=='W') {
                w++;
            }else {
                b++;
            }
        }

        if(w%2 != 0 && b%2 != 0) {
            cout << "NO" << endl;
            continue;
        }

        ll number = 0;
        string idx = "";

        if(b%2 != 0) {
            for(ll i=0; i < n; i++) {
                if(str[i] == 'W') {
                    str[i] = 'B';
                    if(str[i+1] == 'W') str[i+1]='B'; else str[i+1] = 'W';
                    number++;
                    idx.append(to_string(i + 1) + " ");
                }
            }
        }else {
            for(ll i=0; i < n; i++) {
                if(str[i] == 'B') {
                    str[i] = 'W';
                    if(str[i+1] == 'W') str[i+1]='B'; else str[i+1] = 'W';
                    number++;
                    idx.append(to_string(i + 1) + " ");
                }
            }
        }

        cout << "YES" << endl;
        cout << number << endl;
        cout << idx << endl;

    }
    return 0;
}
