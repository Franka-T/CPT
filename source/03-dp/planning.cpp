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

    int n;
    cin >> n;

    vector<ll> difficulties(n);
    for (auto &x : difficulties) cin >> x;

    vector<int> increase(n,1); //aufsteigend
    vector<int> decrease(n,1); //absteigen

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(difficulties[i] > difficulties[j]) {
                increase[i] = max(increase[i], increase[j] + 1);
            }
        }
    }

    for(int i = n-1; i >= 0; i--) {
        for(int j = n-1; j > i; j--) {
            if(difficulties[i] > difficulties[j]) {
                decrease[i] = max(decrease[i], decrease[j] + 1);
            }
        }
    }

    int numOfContest = 0;

    rep(i,n) {
        numOfContest = max(numOfContest, decrease[i] + increase[i]);
    }

    cout << numOfContest - 1 << endl;
}
