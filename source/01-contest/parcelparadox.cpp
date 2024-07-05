
//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <unordered_set>


#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int> >;
using ll = long long;

struct out {
    int length = -1;
    unordered_set<int> path;
};

vector<out> bfs(vector<vector<int> > adj_list, int startNode) {

    vector<out> visited (adj_list.size());
    queue<int> todo;

    visited[startNode].length = 0;
    todo.push(startNode);

    while(!todo.empty()) {
        int currentNode = todo.front();
        todo.pop();

        for(int neighbor : adj_list[currentNode]) {
            if(visited[neighbor].length == -1) {
                visited[neighbor].length = visited[currentNode].length + 1;
                visited[neighbor].path = visited[currentNode].path;
                visited[neighbor].path.insert(currentNode);
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

    int n, a, b;
    cin >> n;

    vector<vector<int> > adj_list (n, vector<int>());
    rep(i, n-1) {
        cin >> a >> b;

        adj_list[a-1].push_back(b-1);
        adj_list[b-1].push_back(a-1);
    }
    int counter = 0;
    vector<out> x;
    int start, end;

    do {
        if(counter > 0) {
            int idx = adj_list.size();
            adj_list.push_back(vector<int>());

            rep(i,n) {
                if(x[end].path.count(i) > 0) {
                    adj_list[i] = vector<int>();
                }else {
                    rep(j, adj_list[i].size()) {
                        if(x[end].path.count(adj_list[i][j]) > 0) {
                            adj_list[i][j] = idx;
                            adj_list[idx].push_back(i);
                        }
                    }
                }
            }
        }

        x = bfs(adj_list, 0);

        int dist = 0;

        rep(i,n) {
            if(dist < x[i].length) {
                dist = x[i].length;
                start = i;
            }
        }

        x = bfs(adj_list, start);

        dist = 0;

        rep(i,n) {
            if(dist < x[i].length) {
                dist = x[i].length;
                end = i;
            }
        }


        if()

    } while (true);










    return 0;
}

