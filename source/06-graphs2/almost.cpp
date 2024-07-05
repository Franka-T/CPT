#include <vector>
#include <iostream>
#include <unordered_set>

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

void unionSet(int p, int q, vector<int> &parent, vector<ll> &sum, vector<unordered_set<int> > &sets){
    if(parent[p] == parent[q]) return;
    
    if(sets[parent[p]].size() < sets[parent[q]].size()) swap(p,q);
    int x = parent[q];

    sum[parent[p]] += sum[x];
    sum[x] = 0;

    for(int node : sets[x]) {
        parent[node] = parent[p];
        sets[parent[p]].insert(node);
    }

    sets[x] = unordered_set<int>();
}

void move(int p, int q, vector<int> &parent, vector<ll> &sum, vector<unordered_set<int> > &sets) {
    if(parent[p] == parent[q]) return;

    sets[parent[p]].erase(p);
    sets[parent[q]].insert(p);

    sum[parent[p]] -= (p + 1);
    sum[parent[q]] += (p + 1);

    parent[p] = parent[q];
}

void printSet(int p, vector<int> &parent, vector<ll> &sum, vector<unordered_set<int> > &sets) {
    cout << sets[parent[p]].size() << " " << sum[parent[p]] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n, m, op, p, q;
    //cin >> n >> m;
    fastScan(n);
    fastScan(m);

    vector<int> parent (n);
    vector<ll> sum(n);
    vector<unordered_set<int> > set(n) ;
    rep(i,n) {
        parent[i] = i;
        sum[i] = i + 1;
        set[i].insert(i);
    }

    rep(i,m) {
        //cin >> op >> p;
        fastScan(op);
        fastScan(p);

        switch (op) {
            case 1:
                //cin >> q;
                fastScan(q);
                unionSet(p - 1, q - 1, parent, sum, set);
                break;
            case 2:
                //cin >> q;
                fastScan(q);
                move(p - 1, q - 1, parent, sum, set);
                break;
            case 3:
                printSet(p - 1, parent, sum, set);
                break;
        }
    }

    return 0;
}

