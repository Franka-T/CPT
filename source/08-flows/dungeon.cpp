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

int getIdx(int x, int y, int w, int h) {
    return (y-1) * w + x;
}

pair<int,int> getCordinates(int idx, int w, int h) {
    int x = idx % w;
    if(x == 0) x = w;
    int y = (idx - x) / w + 1;
    return make_pair(x,y);
}

void createEdge(Graph &adj, Graph &capacity, int start, int end, int c = 1){
    adj[start].emplace_back(end);
    adj[end].emplace_back(start); // reverse edge for residual network
    capacity[start][end] = c;
}

int bfs(Graph &map, Graph &adj_list, vector<int> &parent, int s, int t) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int,int> > q;
    q.push(make_pair(s, INT_MAX));

    while (!q.empty()) {
        int current = q.front().first;
        int current_flow = q.front().second;
        q.pop();

        for (int next : adj_list[current]) {
            if(parent[next] == -1 && map[current][next] > 0) {
                parent[next] = current;
                int new_flow = min(current_flow, map[current][next]);
                if(next == t) return new_flow;
                q.push(make_pair(next,new_flow));
            }
        }
    }
    return 0;
}

int max_flow(Graph &map, Graph &adj_list, int s, int t) {
    int max_flow = 0;
    int new_flow;
    vector<int> parent(map.size());

    while(new_flow = bfs(map, adj_list, parent, s, t)) {
        max_flow += new_flow;
        int current = t;
        while (current != s) {
            int previous = parent[current];
            map[previous][current] -= new_flow;
            map[current][previous] += new_flow;
            current = previous;
        }
    }

    return max_flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    int s, w, h, p, x, y;
    fastScan(s);

    while(s) {
        fastScan(w);
        fastScan(h);
        fastScan(p);
        /*
         * map[1..n] -> input
         * map[n+1...2*n] -> output
         */

        int n = w * h;
        int size = n * 2 + 2;
        int startNode = 0;
        int endNode = 2 * n + 1;

        Graph map(size, vector<int>(size,0));
        Graph adj_list(size, vector<int>());

        for(int i = 1; i <= n; i++) {
            createEdge(adj_list, map, i, i+n); //Kante zwischen input und output Knoten

            pair<int,int> point = getCordinates(i,w,h);

            bool edge = false;

            //Kanten zwischen benachbarten Räumen
            if(point.first > 1) createEdge(adj_list,map,i+n,getIdx(point.first - 1, point.second, w, h)); else edge = true;
            if(point.second > 1) createEdge(adj_list,map,i+n,getIdx(point.first, point.second - 1, w, h)); else edge = true;
            if(point.first < w) createEdge(adj_list,map,i+n,getIdx(point.first + 1, point.second, w, h)); else edge = true;
            if(point.second < h) createEdge(adj_list,map,i+n,getIdx(point.first, point.second + 1, w ,h)); else edge = true;

            if(edge) createEdge(adj_list, map, i + n, 2 * n + 1); //Kante zwischen Rand und endNode
        }

        rep(i,p) {
            fastScan(x);
            fastScan(y);
            createEdge(adj_list, map, 0, getIdx(x,y,w,h));
        }

        int maxflow = max_flow(map, adj_list, 0, (2 * n) + 1);

        if(maxflow >= p) cout << "YES" << endl; else cout << "NO" << endl;

        s--;
    }

    return 0;
}

// 2 3 4 5 1 4 2 2 2 3 2 4 3 3 5 5 5 3 2 2 3 3 3 4 3 3 4