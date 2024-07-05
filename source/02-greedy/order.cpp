
//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <queue>

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

    ll n;
    cin >> n;

    struct task {
        int l,r,idx;

        bool operator<(const task& other) const {
            if(l < other.l) {
                return true;
            }else if(l > other.l){
                return false;
            }else {
                return r < other.r;
            }
        }
    };

    struct taskComparator {
        bool operator()(const task& a, const task& b) const {
            return a.r > b.r; // In diesem Fall wird die Prioritätswarteschlange als Min-Heap behandelt
        }
    };

    vector<task> tasks;
    rep(i,n) {
        int l, r;
        cin >> l >> r;
        task t = {l,r,i+1};
        tasks.push_back(t);
    }

    sort(all(tasks));

    priority_queue<task, vector<task>, taskComparator> possibleTasks;

    int idx = 0;

    for(int i = 1; i <= n; i++) {
        while(idx < n && tasks[idx].l <= i) {
            possibleTasks.push(tasks[idx]);
            idx++;
        }
        cout << possibleTasks.top().idx << " ";
        possibleTasks.pop();
    }

    return 0;
}

