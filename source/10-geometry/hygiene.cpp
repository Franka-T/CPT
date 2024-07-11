#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <float.h>
#include <algorithm>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int> >;
using ll = long long;
using ld = long double;

struct Point {ld x,y;};

bool compareX(Point a, Point b) {
    return a.x < b.x;
}

bool compareY(Point a, Point b) {
    return a.y < b.y;
}

ld dist(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ld bruteForce(vector<Point> &points, int s, int e) {
    ld min_dist = FLT_MAX;

    for(int i = s; i <= e; i++) {
        for(int j = i + 1; j <= e; j++) {
            min_dist = min(min_dist, dist(points[i], points[j]));
        }
    }

    return min_dist;
}

ld stripClosest(vector<Point> &strip, ld d) {
    ld min_dist = d;
    sort(all(strip), compareY);

    for(int i = 0; i < strip.size(); i++) {
        for(int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < min_dist; j++) {
            min_dist = min(min_dist, dist(strip[i], strip[j]));
        }
    }

    return min_dist;
}

ld closestPoints(vector<Point> &points, int s, int e) {
    int n = e - s + 1;
    if (n <= 3) return bruteForce(points, s, e);

    int mid = n / 2 + s - 1;
    Point mid_point = points[mid];

    ld minDistLeft = closestPoints(points, s, mid);
    ld minDistRight = closestPoints(points, mid + 1, e);

    ld min_dist = min(minDistLeft, minDistRight);

    vector<Point> strip;
    for(int i = s; i <= e; i++) {
        if(abs(points[i].x - mid_point.x) < min_dist) strip.push_back(points[i]);
    }

    return stripClosest(strip, min_dist);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    int n;
    cin >> n;

    vector<Point> points(n);

    rep(i,n) {
        cin >> points[i].x >> points[i].y;
    }

    sort(all(points), compareX);
    cout << closestPoints(points, 0, n-1);

    return 0;
}

