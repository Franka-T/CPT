
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
using Graph = vector<vector<int> >;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll x, y, r;
    cin >> x >> y >> r;

    cout << x - r << " " << y - r << endl;
    cout << x + r << " " << y - r << endl;
    cout << x + r << " " << y + r << endl;
    cout << x - r << " " << y + r << endl;




    return 0;
}

