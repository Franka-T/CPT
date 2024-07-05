
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


    int c,a,b;
    cin >> c;

    for(int i = -120; i < 120; i++) {
        for(int j = -120; j < 120; j++) {
            if(pow(i, 5) - pow(j, 5) == c) {
                cout << i << " " << j;
                return 0;
            }
        }
    }


    return 0;
}

