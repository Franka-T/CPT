
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

void printGraph(Graph g) {
    rep(i, g.size()) {
        cout << i << " : ";
        rep(j, g[i].size()) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}

vector<bool> bfs(vector<vector<int>> adj_list, int startNode) {
    vector<bool> visited (adj_list.size(), false);
    queue<int> todo;

    visited[startNode] = true;
    todo.push(startNode);

    while(!todo.empty()) {
        int currentNode = todo.front();
        todo.pop();

        for(int neighbor : adj_list[currentNode]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                todo.push(neighbor);
            }
        }
    }

    return visited;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n, m;
    cin >> n >> m;

    Graph puddles (n, vector<int> ());

    rep(i,m){
        int a, b;
        cin >> a >> b;
        puddles[a].push_back(b);
        puddles[b].push_back(a);
    }

    vector<bool> visited = bfs(puddles, 0);

    rep(i, n) {
        if(!visited[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}

