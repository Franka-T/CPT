
//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <tuple>
#include <cmath>

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

struct street {
    int a;
    int b;
    int dist;

    street(){};

    street(int x, int y, int d) {
        a = x;
        b = y;
        dist = d;
    }
};

vector<ll> dijkstra(vector<vector<pair<int,int> > > &map, int startNode) {
    vector<ll> dist (map.size(), -1);
    vector<bool> visited (map.size(), false);
    priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll, int> > > pq;

    dist[startNode] = 0;
    pq.push(make_pair(0,startNode));

    while(!pq.empty()) {
        pair<ll,int> currentNode = pq.top();
        pq.pop();
        visited[currentNode.second] = true;

        for(auto node : map[currentNode.second]) {
            ll w = node.first + dist[currentNode.second];
            if( w < dist[node.second] || dist[node.second] == -1) {
                dist[node.second] = w;
                if(!visited[node.second]) pq.push(make_pair(w,node.second));
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n, m, a, b, l;
    fastScan(n);
    fastScan(m);

    vector<street> streets;
    vector<vector<pair<int,int> > > map(n, vector<pair<int,int> >());

    rep(i,m) {
        fastScan(a);
        fastScan(b);
        fastScan(l);
        a--;
        b--;
        streets.push_back(street(a,b,l));
        map[a].push_back(make_pair(l,b));
        map[b].push_back(make_pair(l,a));
    }

    vector<ll> dist_Bit = dijkstra(map, 0);
    vector<ll> dist_Nibble = dijkstra(map, 1);

    ll dist_min = dist_Bit[1];
    vector<int> essentials;

    rep(i,m) {
        ll dist1 = streets[i].dist + dist_Bit[streets[i].a] + dist_Nibble[streets[i].b];
        ll dist2 = streets[i].dist + dist_Bit[streets[i].b] + dist_Nibble[streets[i].a];

        if(dist1 == dist_min || dist2 == dist_min) {
            essentials.push_back(i + 1);
        }
    }


    cout << essentials.size() << endl;

    for(int x : essentials) {
        cout << x  << " ";
    }

    cout << endl;

    return 0;
}

