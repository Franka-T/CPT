
//#include <bits/stdc++.h>
#include <vector>
#include <climits>
#include <iostream>
#include <queue>
#include <tuple>
#include <cmath>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int> >;
using ll = long long;


double dijkstra(vector<vector<pair<double,int> > > &map, int startNode, int endNode, int c) {
    vector<double> dist (map.size(), -1);
    vector<bool> visited (map.size(), false);
    priority_queue<pair<double,int>, vector<pair<double,int> >, greater<pair<double, int> > > pq;

    dist[startNode] = 0;
    pq.push(make_pair(0,startNode));

    while(!pq.empty()) {
        pair<double,int> currentNode = pq.top();
        pq.pop();
        visited[currentNode.second] = true;

        for(auto node : map[currentNode.second]) {
            double w = node.first * (c - dist[currentNode.second]);
            if( w < dist[node.second] || dist[node.second] == -1) {
                dist[node.second] = w;
                if(!visited[node.second]) pq.push(make_pair(w,node.second));
            }
        }
    }

    return dist[endNode];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    int n, m, s, t, c;
    cin >> n >> m >> s >> t >> c;
    vector<vector<pair<double,int> > > map (n, vector<pair<double,int> >());

    rep(i,m) {
        int u,v;
        double p;
        cin >> u >> v >> p;
        p *= 0.01;
        map[u-1].push_back(make_pair(p,v-1));
        map[v-1].push_back(make_pair(p,u-1));
    }

    cout << c - dijkstra(map,s-1,t-1,c);



    return 0;
}

