
//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int> >;
using ll = long long;

void switchA(vector<int> &a) {
    a[0]=3;
}

void switchB(vector<int> b) {
    b[0]=3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    vector<int> a (3,1);
    vector<int> b (3,1);

    switchA(a);
    switchB(b);

    rep(i,3){cout << a[i] << " ";}
    cout << endl;
    rep(i,3){cout << b[i] << " ";}
    cout << endl;


    return 0;
}

