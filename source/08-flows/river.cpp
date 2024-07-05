#include <vector>
#include <climits>
#include <iostream>
#include <queue>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int> >;
using ll = long long;

int fastScan(int &number) {
    int c;
    number = 0;
    c = getchar_unlocked();
    for (; (c > 47 && c < 58); c = getchar_unlocked()){
        number = number * 10 + c - 48;
    }
    return number;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    int w, l, c;
    fastScan(w);
    fastScan(l);

    vector<int> river;

    river.push_back(INT_MAX);
    rep(i,w-1) {
        fastScan(c);
        river.push_back(c);
    }
    river.push_back(INT_MAX);

    vector<int> mice (w+1, 0);
    mice[0] = INT_MAX;
    int idx = 0;

    rep(i, w + 1) {
        rep(j, l) {
            int idx = i + l - j;
            if(idx > w) continue;
            if(river[idx] > 0) {
                int num = min(river[idx] - mice[idx], mice[i]);
                mice[idx] += num;
                mice[i] -= num;
            }
        }
    }

    cout << mice[w];

    return 0;
}


// 10 5 0 0 0 0 2 0 0 0 0
// 10 5 0 0 1 0 2 0 0 1 0
// 10 4 0 0 1 0 2 0 0 1 0
// 10 3 1 1 1 1 2 1 1 1 1