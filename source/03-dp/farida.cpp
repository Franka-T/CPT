
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


    int n;
    cin >> n;

    vector<int> monsters(n);
    vector<ll> coins(n);

    rep(i,n) {
        cin >> monsters[i];
    }

    coins[0] = monsters[0];
    if(n > 1) coins[1] = max(monsters[0], monsters[1]);

    for(int i = 2; i < n; i++) {
        coins[i] = max(coins[i-2] + monsters[i], coins[i-1]);
    }

    cout << coins[n-1] << endl;

    return 0;
}
