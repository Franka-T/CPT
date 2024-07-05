
//#include <bits/stdc++.h>
#include <vector>
#include <climits>
#include <iostream>
#include <queue>
#include <tuple>
#include <cmath>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int> >;
using ll = long long;
using ull = unsigned long long;

ll mod = 1000000007;

inline ll mpow(ll b){
    ll ex = mod - 2;
    if (b==1) return 1;
    ll r = 1;
    while (ex){
        if (ex&1)r=(r * b) % mod;
        ex = ex >> 1;
        b = (b * b) % mod;}
    return r;
}


struct testCase {
    ll n;
    ll k;

    testCase(ll n, ll k) {
        this->n = n;
        this->k = k;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int t;
    cin >> t;

    vector<ull> fak;
    fak.push_back(1);
    fak.push_back(1);

    ull max_fak = 1;


    while(t) {
        ull l,h,n;
        cin >> l >> h >> n;

        ull k = h - l;
        n = n - 2 + k;

        if(max_fak < max(k,n)) {
            ull i = max_fak + 1;
            max_fak = max(k,n);

            for(; i <= max_fak; i++) {
                fak.push_back((i * fak[i-1]) % mod);
            }
        }

        cout << fak[n] * mpow(fak[n-k] * fak[k] % mod) % mod << endl;

        t--;
    }


    return 0;
}

