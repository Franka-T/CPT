
//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;



//p(i) is the length of the longest proper prefix of t[0..i], that is also a suffix of t[0..i].
vector<int> prefix_function(string s) {
    int n = s.length();

    vector<int> P(n,0);

    for(int i = 1; i < n; i++) {
        int j = P[i-1];
        while(j > 0 && s.at(i) != s.at(j)) {
            j = P[j - 1];
        }
        if(s.at(i) == s.at(j)) j += 1;
        P[i] = j;
    }

    return P;
}

//z(i) is the length of the longest common prefix of x and x[i..n − 1].
vector<int> z_function(string s) {
    int n = s.length();
    vector<int> vec (n,0);

    int l = 0;
    int r = 0;

    for(int i = 1; i < n; i++) {
        if(i <= r) vec[i] = min(r - i + 1, vec[i - l]);

        while((i + vec[i] < n) && (s.at(vec[i]) == s.at(i + vec[i]))) vec[i] += 1;

        if(i + vec[i] - 1 > r) {
            l = i;
            r = i + vec[i] - 1;
        }
    }
    return vec;
}

//Breitensuche von Adjazenzliste - durchsucht/durchläuft alle erreichbaren Knoten eines Graphen, ausgehend von einem Ausgangskonten
//zunächst alles Knoten, die direkt vom Ausgangsknoten erreichbar sind, danach die nächste "Ebene"
vector<bool> bfs(vector<vector<int>> adj_list, int startNode) {
    /*Zuerst wird ein Startknoten u ausgewählt. Von diesem Knoten aus wird nun jede Kante (u,v) betrachtet und getestet,
     *ob der gegenüberliegende Knoten v schon entdeckt wurde bzw. das gesuchte Element ist. Ist dies noch nicht der Fall,
     *so wird der entsprechende Knoten in einer Warteschlange gespeichert und im nächsten Schritt bearbeitet. Hierbei ist
     *zu beachten, dass Breitensuche immer zuerst alle Knoten der gleichen Ebene bearbeitet, und nicht wie die Tiefensuche
     *einem Pfad in die Tiefe folgt. Nachdem alle Kanten des Ausgangsknotens betrachtet wurden, wird der erste Knoten der
     *Warteschlange entnommen und das Verfahren wiederholt.
     *
     *Die Breitensuche kann für viele Fragestellungen in der Graphentheorie verwendet werden. Einige sind:
     *  - Finde alle Knoten innerhalb einer Zusammenhangskomponente
     *   - Prüfe, ob der gegebene Graph paar ist und finde ggf. eine zulässige 2-Färbung seiner Knoten[4]
     *   - Finde zwischen zwei Knoten u und w einen kürzesten Pfad (ungewichtete Kanten)
     *   - Kürzeste-Kreise-Problem
     */

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

//Tiefensuche von Adjazenzliste
vector<bool> dfs(vector<vector<int>> adj_list, int startNode) {
    stack<int> s;
    vector<bool> visited (adj_list.size(), false);

    s.push(startNode);

    while (!s.empty()) {
        int currentNode = s.top();
        s.pop();

        if(!visited[currentNode]) {
            visited[currentNode] = true;
            for(int edge : adj_list[currentNode]) {
                s.push(edge);
            }
        }

    }
    return visited;
}

//Topologische Sortierung
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

//Bellmann-Ford
// berechnung kürzester wege, ausgehend vom startknoten in kantengewichtetem graphen
// neg kantengewichte erlaubt, kann neg zyklen erkennen siehe trading
template <class T>
vector<T> bellmann_ford(vector<vector<T> > g, int start) {
    int n = g.size();
    vector<T> dist(n, INFINITY);
    vector<int> parent(n);

    dist[0] = 0;

    rep(i,n-1) {
        rep(u,n) {
            rep(v,n) {
                if(dist[v] > dist[u] + g[u][v]) {
                    dist[v] = dist[u] + g[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    return dist;
}

//Dijkstra oder siehe thunder
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

//Union Find - siehe almost

// Prim siehe icecream
struct pairComparator{
    bool operator()(const pair<ll, ll>& a, const pair<ll, ll>& b) const {
        return a.second > b.second;
    }
};

ll prim(vector<vector<pair<ll,ll> > > adj_list) {
    ll n = adj_list.size();
    priority_queue<pair<ll,ll>, vector<pair<ll,ll> >, pairComparator> pq;

    vector<bool> visited (n, false);
    ll sum = 0;

    pq.push(make_pair(0,0));

    while(!pq.empty()) {
        pair<int, int> currentNode = pq.top();
        pq.pop();

        if(!visited[currentNode.first]) {
            sum += currentNode.second;
            visited[currentNode.first] = true;

            for(pair<int, int> node : adj_list[currentNode.first]) {
                if(!visited[node.first]) {
                    pq.push(node);
                }
            }
        }
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    //content


    return 0;
}

