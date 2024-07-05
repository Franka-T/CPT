#include <vector>
#include <iostream>
#include <queue>
#include <cmath>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int> >;
using ll = long long;
using ld = long double;

int fastScan(int &number) {
    int c;
    number = 0;
    c = getchar_unlocked();
    for (; (c > 47 && c < 58); c = getchar_unlocked()){
        number = number * 10 + c - 48;
    }
    return number;
}

struct compare {
    bool operator() (pair<int, ld>p1, pair<int, ld>p2) {
        return p1.second > p2.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(4);
    std::cout << std::fixed;

    int t, n, x, y;
    fastScan(t);

    while(t) {
        fastScan(n);
        vector<pair<int,int> > towns(n, pair<int, int>());
        vector<vector<pair<int, ld> > > roads(n, vector<pair<int, ld> >());

        rep(i,n) {
            fastScan(x);
            fastScan(y);
            towns[i] = make_pair(x,y);

            rep(j,i) {
                ld dx = x - towns[j].first;
                ld dy = y - towns[j].second;
                ld d = sqrt((dx * dx) + (dy * dy));
                if(d <= 10) {
                    roads[i].push_back(make_pair(j,d));
                    roads[j].push_back(make_pair(i,d));
                }
            }
        }

        vector<vector<ld> > dist(n, vector<ld>(n, -1));
        ld max_dist = 0;

        rep(i,n) {
            //dijkstra
            dist[i][i]=0;
            vector<bool> visited (n, false);

            priority_queue<pair<int, ld>, vector<pair<int, ld> >, compare> pq;
            pq.push(make_pair(i,0));

            while(!pq.empty()) {

                int currentNode = pq.top().first;
                ld currentNodeDist = pq.top().second;
                pq.pop();
                visited[currentNode] = true;

                for(pair<int,ld> x : roads[currentNode]) {
                    int node = x.first;
                    ld nodeDist = x.second;

                    if(dist[i][node] > currentNodeDist + nodeDist || dist[i][node] == -1) {
                        dist[i][node] = currentNodeDist + nodeDist;
                        if(!visited[node])pq.push(make_pair(node, currentNodeDist + nodeDist));
                    }
                }
            }

            rep(j,n) {
                if (dist[i][j] == -1) {
                    cout << "Send Kurdy"<< endl;
                    goto end;
                }
                max_dist = max(max_dist, dist[i][j]);
            }

        }

        cout << max_dist << endl;

        end:;
        t--;
    }

    return 0;
}

