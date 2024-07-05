#include <vector>
#include <iostream>
#include <queue>

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


    ll n, m;
    cin >> n >> m;

    vector<ll> items (3,0);

    rep(i,n) {
        int x;
        cin >> x;
        items[x-1]++;
    }

    ll x = 0;
    ll w = 0;

    bool drei = false;

    x = min(m/3, items[2]);
    w += x * 3;
    if(x > 0) drei = true;

    x = min((m-w)/2, items[1]);
    w += x * 2;
    items[1] -= x;

    x = min((m-w), items[0]);
    w += x;


    // siehe Beispiel 3 4 3 2 2
    if(m - w == 1 && items[1] >= 2 && drei) w = m;

    cout << w << endl;

    return 0;
}

