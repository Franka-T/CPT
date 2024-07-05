
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

    k--;

    m -= n;
    int highscore = 1;

    int l = max(k,0);
    int l_fix = l;
    int r = max(n - k - 1,0);
    int r_fix = r;
    int add = 0;


    if(m>0) {
        m--;
        highscore++;
    }

    while(m > 0 && (l != 0 && r != 0)) {
        add += 1;

        if(r > 0 ) {
            add += 1;
            r--;
        }

        if(l > 0) {
            add++;
            l--;
        }

        add = min(n, add);
        m -= add;
        if(m >= 0) highscore += 1;
    }



    if(m > 0) {
        int x = m/k;
        highscore += x;
    }

    cout << highscore;




    return 0;
}

