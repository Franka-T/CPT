
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


    int t;
    cin >> t;

    while(t) {
        long double x_1, y_1, r_1, x_2, y_2, r_2;
        cin >> x_1 >> y_1 >> r_1;
        cin >> x_2 >> y_2 >> r_2;

        long double dist = sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
        long double r = r_1 + r_2;

        if(dist == 0) { // gleicher mittelpunkt
            if(r_1 == r_2) {
                if(r_1 == 0) {
                    cout << "1" << endl;
                } else {
                    cout << "oo" << endl; // gleicher Radius -> identisch -> oo
                }
            } else {
                cout << "0" << endl; // ein kreis größer als der andere -> 0
            }
        } else if(dist > r) { // dist größer als summe der radien -> 0
            cout << "0" << endl;
        } else if(dist == r){ // dist = summe der radien -> 1
            cout << "1" << endl;
        } else { //dist < summe der radien
            if(dist + min(r_1,r_2) < max(r_1,r_2)) {
                cout << "0" << endl;
            } else if(dist + min(r_1,r_2) == max(r_1,r_2)) {
                cout << "1" << endl;
            }else {
                cout << "2" << endl;
            }
        }

        t--;
    }


    return 0;
}

