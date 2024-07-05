
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


    int n, a, b;
    cin >> n;

    vector<vector<int> > adj_list (n, vector<int>());
    rep(i, n-1) {
        cin >> a >> b;

        adj_list[a-1].push_back(b-1);
        adj_list[b-1].push_back(a-1);
    }


    return 0;
}

