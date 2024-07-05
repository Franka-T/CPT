
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

struct leaf {
    int mit = 0;
    int ohne = 0;
};

leaf treeDFS (vector<vector<int>> & adj_list, vector<int> & fun, int currentNode) {
    leaf sum;
    sum.mit += fun[currentNode];

    //für jedes Kind schauen
    for(int neighbor : adj_list[currentNode]) {
        sum.mit += treeDFS(adj_list, fun, neighbor).ohne; //wenn ich aktuellen fun nehmen möchte, darf Kind nicht dabei sein
        sum.ohne += max(treeDFS(adj_list, fun, neighbor).mit, treeDFS(adj_list, fun, neighbor).ohne); // wenn aktueller fun nicht genoomen, wird, dann bisher möglicher max
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n;
    cin >> n;

    vector<int> fun(n);
    rep(i,n) cin >> fun[i];

    Graph adj_list (n, vector<int>());
    for(int i = 1; i < n; i++) {
        int boss;
        cin >> boss;
        adj_list[boss - 1]. push_back(i);
    }

    leaf  out = treeDFS(adj_list, fun, 0);

    cout << max(out.mit, out.ohne) << endl;

    return 0;
}

