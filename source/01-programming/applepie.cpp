
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

    long t, h, p, n;

    cin >> t;

    while(t>0) {
        cin >> h >> p;
        priority_queue<tuple<int,int,int>> pony;
        rep(i,h) {
            cin >> n;
            pony.push(tuple<int,int,int> (n,n,1));
        }

        p -= h;
        while(p>0) {
            int x = get<0>(pony.top());
            n = get<1>(pony.top());
            double a = get<2>(pony.top());
            if(x == 1) break;
            pony.pop();
            a++;
            x = ceil(n/a);
            pony.push(tuple<int,int,int> (x,n,a));
            p--;
        }

        cout << get<0>(pony.top()) << endl;

        t--;
    }


    return 0;
}

/*PROBLEM:
 * aktuell
 **/