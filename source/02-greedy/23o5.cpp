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

ll op(ll a, ll b, int op) {
    switch (op) {
        case 0:
            return a + b;
        case 1:
            return a - b;
        case 2:
            return a * b;
    }
    return 0;
}

bool is_possible(vector<ll> vec) {
    do {
        /*
        for(int a : {0,1,2}) {
            for(int b : {0,1,2}) {
                for(int c : {0,1,2}) {
                    for(int d : {0,1,2}) {
                        vector<int> operators = {a,b,c,d};
                        ll x = vec[0];
                        for(int i = 1; i < 5 ; i++){
                            x = op(x, vec[i], operators[i-1]);
                        }
                        //ll x = op(op(op(op(vec[0],vec[1],a), vec[2], b), vec[3], c), vec[4], d);
                        if(x == 23) {
                            return true;
                        }
                    }
                }
            }
        }*/

        for(int i = 0; i < 81; i++) {
            ll a = i % 3;
            ll b = (i / 3) % 3;
            ll c = (i / 9) % 3;
            ll d = (i / 27) % 3;

            ll x = op(op(op(op(vec[0],vec[1],a), vec[2], b), vec[3], c), vec[4], d);
            if(x == 23) {
                return true;
            }
        }
    }while(next_permutation(all(vec)));
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    int t;
    cin >> t;

    while(t>0) {
        bool possible = false;
        vector<ll> vec(5,0);
        for(auto& e : vec) cin>>e;

        sort(all(vec));

        if(is_possible(vec)) {
            cout << "Possible" << endl;
        } else {
            cout << "Impossible" << endl;;
        }

        t--;
    }

    return 0;
}

