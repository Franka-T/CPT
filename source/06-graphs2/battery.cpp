#include <vector>
#include <iostream>
#include <queue>
#include <cmath>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'
#define INFINITY ((int)(2147483647))

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

    struct point {
        int dist, city;

        point(int a, int b) {
            dist = a;
            city = b;
        }

        bool operator<(const point& other) const {
            return dist > other.dist;
        }
    };

    struct pointComparator {
        bool operator()(const point& a, const point& b) const {
            return a.dist > b.dist;
        }
    };


    int t, n, m, a, b, w;
   fastScan(t);

    while(t) {
        fastScan(n);
        fastScan(m);
        vector<vector<point> > cities (n, vector<point>());
        rep(i,m) {
            fastScan(a);
            fastScan(b);
            fastScan(w);
            cities[a].push_back(point(w, b));
            cities[b].push_back(point(w,a));
        }

        vector<int> dist (n, INFINITY);

        dist[0]=0;

        priority_queue<point, vector<point>, pointComparator> pq;
        pq.push(point(0, 0));

        while(!pq.empty()) {
            point currentCity = pq.top();
            pq.pop();

            for(point node : cities[currentCity.city]) {
                if(max(dist[currentCity.city], node.dist) < dist[node.city]) {
                    dist[node.city] = max(dist[currentCity.city], node.dist);
                    pq.push(point(dist[node.city], node.city));
                }
            }
        }

        sort(all(dist));

        int idx = ceil((n - 1.0) * 3.0 / 4);

        cout << dist[idx] << endl;

        t--;
    }


    return 0;
}

