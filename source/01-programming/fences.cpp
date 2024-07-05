
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

    long n,m;
    cin >> n >> m;

    vector<ll> fence;

    rep(i,m) {
        ll l,r,c;
        cin >> l >> r >> c;
        for(ll j = l; j < r; j++) {
            fence[j]=c;
        }



    }


    //content


    return 0;
}

