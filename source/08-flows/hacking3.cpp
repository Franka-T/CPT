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


bool bfs(vector<vector<int> > g, int s, int t, vector<int> &parent) {
    vector<bool> visited(g.size(), false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        rep(i, g.size()) {
            if(!visited[i] && g[u][i] > 0) {
                if(i == t) {
                    parent[i] = u;
                    return true;
                }
                q.push(i);
                visited[i] = true;
                parent[i] = u;
            }
        }
    }

    return false;
}

void dfs(vector<vector<int> > &residual_g, int s, vector<bool> &visited) {
    visited[s] = true;
    rep(i,residual_g.size()) {
        if(residual_g[s][i] && !visited[i]) {
            dfs(residual_g,i,visited);
        }
    }
}

ll minCut(vector<vector<int> > &g, int s, int t, vector<bool> &visited) {
    vector<vector<int > > residual_g(g.size(), vector<int>(g.size()));
    rep(i,g.size()) {
        rep(j,g.size()) {
            residual_g[i][j] = g[i][j];
        }
    }

    vector<int> parent(g.size());
    ll max_flow = 0;
    ll u;

    while(bfs(residual_g,s,t,parent)) {
        int path_flow = INT_MAX;

        for(int v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, residual_g[u][v]);
        }

        for(int v = t; v != s; v = parent[v]) {
            u = parent[v];
            residual_g[u][v] -= path_flow;
            residual_g[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

   //vector<bool> visited(g.size(), false);
    dfs(residual_g, s, visited);

    return max_flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n, m, u, v, t;
    fastScan(n);
    fastScan(m);

    vector<vector<int> > g (n,vector<int>(n,0));
    vector<vector<int> > idx (n, vector<int>(n,-1));
    vector<bool> visited(n, false);

    rep(i,m) {
        fastScan(u);
        fastScan(v);
        fastScan(t);
        g[u-1][v-1] = t;
        idx[u-1][v-1] = i + 1;
    }

    ll max_flow = minCut(g, 0, n-1, visited);

    vector<int> connections;

    for (int i = 0; i < g.size(); i++)
        for (int j = 0; j < g.size(); j++)
            if (visited[i] && !visited[j] && g[i][j])
                connections.push_back(idx[i][j]);

    cout << connections.size() << " " << max_flow << endl;
    rep(i, connections.size()) {
        cout << connections[i] << " ";
    }

    return 0;
}

