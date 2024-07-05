
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n, m, k;
    cin >> n >> m >> k;

    int highscore = m / n;
    m -= highscore * n;

    //vector<int> backyard (n,start);
    //if(m > 0) backyard[k] += 1;

    int l = max(k - 1,0);
    int r = max(n - k,0);

    m += max(0, (l - 1) * 2 + 1);
    m += max(0,(r - 1) * 2 + 1);

    highscore += m/n;

    cout << highscore;




    return 0;
}

