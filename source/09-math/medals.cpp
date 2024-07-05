#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <unordered_set>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int> >;
using ll = long long;

unordered_set<int> primeFactors(int x) {
    unordered_set<int> primes;
    while(x % 2 == 0) {
        primes.insert(2);
        x /= 2;
    }

    for(int i = 3; i <= sqrt(x); i += 2) {
        while(x % i == 0) {
            primes.insert(i);
            x /= i;
        }
    }

    if(x > 2) primes.insert(x);

    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    int n;
    cin >> n;

    vector<int> importance(n);
    rep(i,n) cin >> importance[i];

    vector<int> submissions (importance[n-1] + 1,0);
    int max_sub = 0;

    for(int x : importance) {
        unordered_set<int> prims = primeFactors(x);

        int a = 0;
        for(int p : prims) {
            a = max(a, submissions[p]);
        }
        max_sub = max(max_sub, a + 1);
        for(int p : prims) {
            submissions[p] = a + 1;
        }
    }

    cout << max_sub;

    return 0;
}

