
//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <map>
#include<set>
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

    int t;
    cin >> t;

    while(t>0) {
        long n;
        cin >> n;

        vector<ll> snowflakes;
        ll x;

        rep(i,n) {
            cin >> x;
            snowflakes.push_back(x);
        }

        int max = 0;
        //int idx = 0;

        rep(i,n) {
            set<ll> m;
            bool end = false;
            int c = 0;

            for(int j = i; j < n; j++) {
                if(m.find(snowflakes[j]) != m.end()) { //bereits in set enthalten
                    //i = j;
                    while(snowflakes[i]!=snowflakes[j]) i++;
                    break;
                }
                m.insert(snowflakes[j]);
                c++;
                if(c > max) max = c;

                if(j == n-1) {
                    end = true;
                }
            }

            if(end) break;

        }

        cout << max << endl;

        t--;
    }


    return 0;
}

