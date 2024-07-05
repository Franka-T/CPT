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

const int MOD = 998244353;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll size = 2000;

    vector<vector<ll>> dp(size, vector<ll>(size,0));

    rep(i,size) dp[i][0]=1;

    for(int n = 1; n < size; n++) {
        for(int p = 1; p <= n; p++) {
            ll x = ((p+1) * dp[n-1][p]) % MOD; // still p blocks
            ll y = ((n-p+1) * dp[n-1][p-1]) % MOD; // p + 1 blocks

            dp[n][p] = (x + y) % MOD;
            //dp[n][p] = (((p+1) * dp[n-1][p]) + ((n-p+1) * dp[n-1][p-1])) % MOD;
        }
    }

    int t, n, p;
    cin >> t;

    while(t) {
        cin >> n >> p;
        cout << dp[n-1][p-1] << endl;
        t--;
    }


    return 0;
}


