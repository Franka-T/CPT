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

ll ford_fulkerson (vector<vector<int> > &g, int s, int t) {
    vector<vector<int> > residual_g (g.size(), vector<int>(g.size()));
    rep(i,g.size()) {
        rep(j,g.size()) {
            residual_g[i][j] = g[i][j];
        }
    }

    vector<int> parent(g.size());
    int max_flow = 0;
    int u;

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
    return max_flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    int n, m;
    cin >> n >> m;

    vector<vector<int> > g(n, vector<int>(n, 0));

    rep(i,m) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a-1][b-1] += c;
        g[b-1][a-1] += c;
    }

    cout << ford_fulkerson(g,0,1) << endl;




    return 0;
}

//2 2 1 2 1 2 1 3

//4 5 1 4 1 1 3 2 3 4 1 4 2 2 3 2 1