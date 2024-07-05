
//#include <bits/stdc++.h>
#include <vector>
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

bool sortbyorder(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.first == a.second) {
        return (a.second > b.second);
    }
    return (a.first < b.second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll numberOfParticipants, first, second;
    cin >> numberOfParticipants;

    vector<vector<ll> > participants(numberOfParticipants, vector<ll>(2));
    for (ll i = 0; i < numberOfParticipants; i++) {
        cin >> first;
        cin >> second;

        participants[i][0] = first;
        participants[i][1] = second;
    }
    if (numberOfParticipants % 2 != 0) {
        cout << "impossible" << endl;
        return 0;
    }

    sort(participants.begin(), participants.end(), sortbyorder);

    ll maxFirst = participants.front()[0] + participants.back()[0];
    ll maxSecond = participants.front()[1] + participants.back()[1];

    for (ll i = 0; i < numberOfParticipants / 2; i++) {
        first = participants[i][0] + participants[numberOfParticipants - i - 1][0];
        second = participants[i][1] + participants[numberOfParticipants - i - 1][1];
        if (maxFirst != first || maxSecond != second) {
            cout << "impossible" << endl;
            return 0;
        }
    }
    cout << "possible" << endl;
    return 0;
}

