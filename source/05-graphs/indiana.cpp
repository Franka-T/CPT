#include <vector>
#include <iostream>
#include <queue>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int> >;
using ll = long long;

vector<int> topo_sort(vector<vector<int> > adj_list, vector<int> in_deg) {
    queue<int> q;
    vector<int> result;
    bool multiple = false;

    rep(i, adj_list.size()) if(in_deg[i] == 0) q.push(i);

    while(!q.empty()) {
        if(q.size() > 1) multiple = true;
        int node = q.front();
        q.pop();
        result.push_back(node);

        for(auto it: adj_list[node]) {
            in_deg[it]--;
            if (in_deg[it] == 0) q.push(it);
        }
    }

    if(multiple) result[0] = -1;

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int t;
    cin >> t;

    while(t) {
        int n, h;
        cin >> n >> h;

        vector<vector<int> > adj_list (n);
        vector<int> in_deg(n,0);

        rep(i,h) {
            int a, b;
            cin >> a >> b;
            adj_list[a - 1].push_back(b - 1);
            in_deg[b - 1]++;
        }

        vector<int> result = topo_sort(adj_list, in_deg);

        if(result.size() != n) {
            cout << "recheck hints" << endl;
        }else if(result[0] == -1) {
            cout << "missing hints" << endl;
        }else{
            rep(i,n) cout << result[i] + 1 << " ";
            cout << endl;
        }
        t--;
    }


    return 0;
}

