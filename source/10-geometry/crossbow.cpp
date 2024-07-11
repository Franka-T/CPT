#include <vector>
#include <climits>
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

struct Point {float x, y;};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int t;
    cin >> t;
    double start_x,start_y,end_x,end_y;

    rep(i,t){
        cin >> start_x >> start_y;
        cin >> end_x >> end_y;

        double shoot_x,shoot_y;
        shoot_x = end_x - start_x;
        shoot_y = end_y - start_y;

        int n;
        cin>>n;

        int counter = 0;
        double balloon_x,balloon_y,r;

        rep(j,n){
            cin >> balloon_x >> balloon_y >> r;
            double centerX = balloon_x - start_x;
            double centerY = balloon_y - start_y;
            double centerDist = sqrt(centerX * centerX + centerY * centerY);

            if(centerDist < r){
                counter++;
                continue;
            }

            double dotProduct = (shoot_x * centerX + shoot_y * centerY) / (centerDist * sqrt(shoot_x * shoot_x + shoot_y * shoot_y));
            if(dotProduct < 0) continue;

            float alpha = sin(acos(dotProduct));

            float dist = centerDist * alpha;
            if(dist<=r) counter += 1;

        }
        cout << counter << endl;

    }

    return 0;
}

/*
2
0 4 10 4
5
5 7 1
2 4 1
5 4 1
8 4 1
5 1 1
2 6 10 0
4
1 7 1
4 5 1
7 4 1
8 1 1

*/