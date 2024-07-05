
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


    ll n,u;
    cin >> n >> u;

    vector<ll> vec(n,0);
    for(auto& e : vec) cin>>e;

    sort(all(vec), std::greater<ll>());

    ll sum = 0;
    ll i = 1;

    while(i <= n) {
        sum += vec[i-1];
        if(sum < u * i) {
            break;
        }
        i++;
    }

    cout << i-1 << endl;


    return 0;
}

