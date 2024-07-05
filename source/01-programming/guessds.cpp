
//#include <bits/stdc++.h>
#include <vector>
#include <iostream>

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

    cout << "? insert 3" << endl;
    cout.flush();
    cout << "? insert 1" << endl;
    cout.flush();
    cout << "? insert 1" << endl;
    cout.flush();
    cout << "? insert 2" << endl;
    cout.flush();

    cout << "? remove" << endl;
    cout.flush();

    int x;
    cin >> x;

    switch(x) {
        case -1:
            return 0;
        case 3:
            cout << "! queue";
            cout.flush();
            return 0;
        case 2:
            cout << "! stack";
            cout.flush();
            return 0;
        default :
            cout << "? remove" << endl;
            cout.flush();
            cin >> x;
             if(x == -1) {
                 return 0;
             }else if(x == 2){
                 cout << "! set";
             }else {
                 cout << "! pq";
             }
    }

    return 0;
}

