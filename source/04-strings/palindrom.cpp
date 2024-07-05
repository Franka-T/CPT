
//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
#include <cmath>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'
#define printAll2d(l) for(auto elem:l){for(auto el:elem)cout<<el<<" ";cout<<endl;}cout<<endl;

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    string s1, s2;
    getline(cin, s1);
    s2 = s1;
    reverse_copy(s1.begin(),s1.end(), begin(s2));

    int size = s1.length();
    vector<vector<int>> dp (size, vector<int> (size, 0));

    rep(i,size) {
        dp[i][0] = i;
        dp[0][i] = i;
    }

    for(int i = 1; i < size; i++) {
        for(int j = 1; j < size; j++) {
            int t = min(dp[i-1][j],dp[i][j-1]);
            int x = 0;
            if(s1[i] != s2[j]) x = 1;

            dp[i][j] = min(t + 1, dp[i-1][j-1] + x);
        }
    }

    cout << ceil(dp[size - 1][size - 1] / 2.0) << endl;

    return 0;
}

