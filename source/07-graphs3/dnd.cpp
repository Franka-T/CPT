
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n,m,q,a,b;
    cin >> n;
    vector<pair<ll,ll> > proficiency(n);
    rep(i,n) {
        cin >> proficiency[i].first >> proficiency[i].second;
    }

    cin >> m;
    vector<vector<pair<ll,int> > > g (n, vector<pair<ll,int> >()); //cost,b
    rep(i,m) {
        cin >> a >> b;
        a--;
        b--;

        ll cost1 = (proficiency[a].first - proficiency[b].first) * (proficiency[a].first - proficiency[b].first);
        ll cost2 = (proficiency[a].second - proficiency[b].second) * (proficiency[a].second - proficiency[b].second);
        ll cost = cost1 + cost2;

        g[a].push_back(make_pair(cost,b));
        g[b].push_back(make_pair(cost, a));
    }

    cin >> q;
    vector<vector<ll> > dist (n, vector<ll>(n, -1));
    vector<bool> finished(n, false);

    rep(i,q) {
        cin >> a >> b;
        a--;
        b--;

        if(!finished[a] && !finished[b]) {
            dist[a][a] = 0;
            vector<bool> visited (n, false);
            priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll, int> > > pq;

            pq.push(make_pair(0,a));

            while (!pq.empty()) {
                pair<ll,ll> currentNode = pq.top();
                pq.pop();
                visited[currentNode.second] = true;

                for(auto x : g[currentNode.second]) {
                    ll w = x.first + dist[a][currentNode.second];
                    if(w < dist[a][x.second] || dist[a][x.second] == -1) {
                        dist[a][x.second] = w;
                        if(!visited[x.second]) pq.push(make_pair(w,x.second));
                    }
                }
            }
            finished[a] = true;
        }

        if(!finished[a]) swap(a,b);

        if(dist[a][b] == -1) cout << "BRIBE DM WITH FOOD" << endl; else cout << dist[a][b] << endl;
    }

    return 0;
}

// 5 0 3 1 1 4 2 -1 3 2 -4 4 1 2 3 4 1 3 1 4 3 1 5 2 4 3 2