
//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <queue>


#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

struct leaf {
    ll mit = 0;
    ll ohne = 0;
};

vector<int> topo_sort(vector<vector<int>> adj_list, vector<int> in_deg) {
    //in_deg Anzahl der eingehnden Kanten pro Knoten
    vector<int> res;
    int n = adj_list.size();
    rep(i,n) if (in_deg[i] == 0) res.push_back(i);
    rep(i,n) {
        for(int v : adj_list[res[i]]) {
            if (!--in_deg[v]) res.push_back(v);
        }
    }
    return res;
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
    vector<int> in_deg (n,1);
    in_deg[0] = 0;

    for(int i = 1; i < n; i++) {
        int boss;
        cin >> boss;
        adj_list[boss - 1]. push_back(i);
    }

    vector<int> sorted = topo_sort(adj_list, in_deg);

    vector<leaf> out (n);

    for(int i = n-1;i >= 0; i--) {
        int currentNode = sorted[i];

        out[currentNode].mit += fun[currentNode];

        for(int child : adj_list[currentNode]) {
            out[currentNode].mit += out[child].ohne;
            out[currentNode].ohne += max(out[child].ohne, out[child].mit);
        }
    }

    cout << max(out[0].mit, out[0].ohne) << endl;

    return 0;
}

