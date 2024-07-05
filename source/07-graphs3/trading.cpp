#include <vector>
#include <iostream>
#include <climits>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int> >;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n;
    cin >> n;
    vector<string> currency_codes (n);
    vector<vector<double> > exchange_rates(n,vector<double>(n));

    rep(i,n) {
        cin >> currency_codes[i];
    }

    rep(i,n) {
        rep(j,n) {
            double a;
            cin >> a;
            exchange_rates[i][j] = a * -1;
        }
    }

    // Bellmann-Ford
    vector<long double> dist(n,LLONG_MAX);
    vector<int> parent(n);

    dist[0] = 0;

    rep(i,n-1) {
        rep(u,n) {
            rep(v,n) {
                if(dist[v] > dist[u] + exchange_rates[u][v]) {
                    dist[v] = dist[u] + exchange_rates[u][v];
                    parent[v] = u;
                }
            }
        }
    }
    // Bellmann-Ford end

    int x = -1;

    //checks for neg-cycle
    rep(u,n) {
        rep(v,n) {
            if(dist[u] + exchange_rates[u][v] < dist[v]) {
                x = v;
                goto step;
            }
        }
    }

    step:;

    if(x == -1) {
        cout << "noglitch" << endl;
        return 0;
    }

    // looky for an element of the cylce
    vector<bool> visited (n,false);
    while(!visited[x]) {
        visited[x] = true;
        x = parent[x];
    }

    vector<int> order;
    int end = x;
    x = parent[x];

    while (x != end) {
        order.push_back(x);
        x = parent[x];
    }
    order.push_back(x);

    cout << "money!" << endl;
    cout << order.size() << endl;
    rep(i,order.size()) cout << currency_codes[order[order.size() - i - 1]] << " ";

    return 0;
}

