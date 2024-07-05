
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


    ll n, s;
    cin >> n;

    bool found = true;

    while(found) {
        s = sqrt(n);
        found = false;

        for(int i = 2; i <= s; i++) {
            int x = n % i;
            if(n % i == 0) {
                n = n / i;
                found = true;
                break;
            }
        }
    }

    cout << n;





    return 0;
}

