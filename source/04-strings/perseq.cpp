
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

vector<int> z_function(string s) {
    //z(i) is the length of the longest common prefix of x and x[i..n − 1].
    int n = s.length();
    vector<int> vec (n,0);

    int l = 0;
    int r = 0;

    for(int i = 1; i < n; i++) {
        if(i <= r) vec[i] = min(r - i + 1, vec[i - l]);

        while((i + vec[i] < n) && (s.at(vec[i]) == s.at(i + vec[i]))) vec[i] += 1;

        if(i + vec[i] - 1 > r) {
            l = i;
            r = i + vec[i] - 1;
        }
    }
    return vec;
}

bool equal(string s1, string s2) {
    while (s2.length() < 3 * s1.length()) {
        s2 += s2;
    }

    string s = s1 + '#' + s2;

    vector<int> z = z_function(s);

    for(int i = 0; i < s.length(); i++) {
        if(z[i] == s1.length()) {
            if(i + s1.length() < s.length() && z[i + s1.length()] == s1.length()) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    int n, m;
    cin >> n >> m;

    string s1 = "";
    string s2 = "";
    char c;
    rep(i,n) {
        cin >> c;
        s1 += c;
    }

    rep(i,m) {
        cin >> c;
        s2 += c;
    }

    bool x;
    if(n < m) x = equal(s2, s1); else x = equal(s1, s2);

    if(x) cout << "YES" << endl; else cout << "NO" << endl;

    return 0;
}

