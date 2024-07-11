#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n' //comment this out for interactive problems

using namespace std;
using Graph = vector<vector<int> >;
using ll = long long;

template <typename T>
using point = pair<T, T>;

ll crossProduct(point<ll> p1, point<ll> p2) {
    return p1.first * p2.second - p1.second * p2.first;
}

point<ll> vec(point<ll> p1, point<ll> p2) {
    return point<ll>(p1.first - p2.first, p1.second - p2.second);
}

bool sortGreater(size_t p1, size_t p2) {
    return p1 > p2;
}

set<size_t> convex_hull(vector<point<ll> > &points){
    int n = points.size();

    sort(all(points));
    list<size_t> upper_hull;
    list<size_t> lower_hull;
    list<size_t> hull;
    set<size_t> indices;

    if(n <=3){
        rep(i,n) indices.insert(i);
        return indices;
    }

    //lower hull
    for(size_t i = 0; i < n; i++){
        while(lower_hull.size() > 1){
            auto last = prev(lower_hull.end());
            auto sec_last = prev(last);
            if (crossProduct(vec(points[*sec_last], points[*last]), vec(points[*last], points[i])) >= 0)
                break;
            lower_hull.pop_back();
        }
        lower_hull.push_back(i);
    }

    //upper hull
    for(int i = n - 1; i >= 0; i--){
        while(upper_hull.size() > 1){
            auto last = prev(upper_hull.end());
            auto sec_last = prev(last);
            if (crossProduct(vec(points[*sec_last], points[*last]), vec(points[*last], points[i])) >= 0)
                break;
            upper_hull.pop_back();
        }
        upper_hull.push_back(i);
    }

    indices.insert(all(lower_hull));
    indices.insert(all(upper_hull));

    return indices;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int t, n, counter;
    cin >> t;

    while(t){
        cin >> n;

        vector<point<ll> > points(n);
        rep(i,n) cin >> points[i].first >> points[i].second;

        counter = 0;

        while(!points.empty()){
            set<size_t> hull = convex_hull(points);
            list<size_t> indices(all(hull));
            indices.sort(sortGreater);
            for(auto& idx : indices) points.erase(points.begin() + idx);
            counter++;
        }

        cout << counter << endl;

        t--;
    }

    return 0;
}