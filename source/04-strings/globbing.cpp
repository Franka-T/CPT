#include <vector>
#include <iostream>
#include <queue>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'
#define printAll(l) for(auto elem:l)cout<<elem<<" ";cout<<endl;
#define printNo     cout << "No" << endl; continue;
#define printYes    cout << "Yes" << endl; continue;

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int t;
    cin >> t;
    string pattern, str;
    getline(cin, str);

   rep(a,t) {
        getline(cin, pattern);
        getline(cin, str);

        int sizePattern = pattern.length();
        int sizeStr = str.length();

        if(sizePattern == 0 && sizeStr == 0) {printYes}
        if(sizeStr + 1 < sizePattern) {printNo}

        int i = 0;
        while(i < min(sizeStr,sizePattern) && pattern[i] == str[i]) {
            i++;
        }

        if(i == sizeStr && i == sizePattern) {printYes}

        if(pattern[i] != '*' && pattern[i] != '+') {printNo}

        if(pattern[i] == '+' && sizePattern > sizeStr) {printNo}

        int p = sizePattern - 1;
        int s = sizeStr - 1;

        bool end = false;
        while(p > i) {
            if(pattern[p] != str[s]) {
                end = true;
                break;
            }
            p--;
            s--;
        }

        if(end) {printNo}

        cout << "Yes" << endl;
    }


    return 0;
}

