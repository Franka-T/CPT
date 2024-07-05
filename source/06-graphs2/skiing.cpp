#include <vector>
#include <iostream>

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

    int t, n, m, u, v, w;
    fastScan(t);
    while(t) {
        //cin >> n >> m;
        fastScan(n);
        fastScan(m);

        vector<vector<pair<int, int> > > resort (n, vector<pair<int,int> >());
        vector<int> in_deg(n, 0);

        rep(i,m){
            //cin >> u >> v >> w;
            fastScan(u);
            fastScan(v);
            fastScan(w);
            resort[u - 1].push_back(make_pair(v - 1,w));
            in_deg[v - 1]++;
        }

        vector<int> sorted_resort;
        rep(i,n) if (in_deg[i] == 0) sorted_resort.push_back(i);
        rep(i,n) {
            for(pair<int,int> v : resort[sorted_resort[i]]) {
                if (!--in_deg[v.first]) sorted_resort.push_back(v.first);
            }
        }

        vector<int> longest_path (n,0);
        int max = 0;

        rep(i,n) {
            int idx = sorted_resort[i];
            for(pair<int,int> x : resort[idx]) {
                if(longest_path[x.first] < longest_path[idx] + x.second) {
                    longest_path[x.first] = longest_path[idx] + x.second;
                    if(longest_path[x.first] > max) max = longest_path[x.first];
                }
            }
        }

        cout << max << endl;
        t--;
    }

    return 0;
}
