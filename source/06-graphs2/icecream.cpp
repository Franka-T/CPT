#include <vector>
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

struct pairComparator{
    bool operator()(const pair<ll, ll>& a, const pair<ll, ll>& b) const {
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n, m, a, b, c;
    fastScan(n);
    fastScan(m);

    vector<vector<pair<ll, ll> > > possible_pips(n + 1, vector<pair<ll, ll> >());

    rep(i,n) {
        fastScan(c);
        possible_pips[i].push_back(make_pair(n, c));
        possible_pips[n].push_back(make_pair(i, c));
    }

    rep(i, m) {
        fastScan(a);
        fastScan(b);
        fastScan(c);
        possible_pips[a].push_back(make_pair(b, c));
        possible_pips[b].push_back(make_pair(a, c));
    }

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

            for(pair<int, int> node : possible_pips[currentNode.first]) {
                if(!visited[node.first]) {
                    pq.push(node);
                }
            }
        }
    }

    cout << sum << endl;


    return 0;
}

