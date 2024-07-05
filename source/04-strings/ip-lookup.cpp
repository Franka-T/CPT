#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
#include <cmath>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    struct Node {
        bool star = false;
        bool end = false;
        //string data = "";
        struct Node *zero = nullptr;
        struct Node *one = nullptr;
        struct Node *root = nullptr;
    };

    ll n, m;
    cin >> n;

    Node* activeIPs = new Node();
    activeIPs->root = activeIPs;

    Node* currentNode = activeIPs;

    string s;
    getline(cin, s);

    rep(i,n) {
        getline(cin, s);
        currentNode = currentNode->root;
        for(char c : s) {
            switch (c) {
                case '*':
                    currentNode->star=true;
                    break;
                case '0':
                    if(currentNode->zero == nullptr) {
                        currentNode->zero = new Node();
                        currentNode->zero->root = currentNode->root;
                    }
                    currentNode = currentNode->zero;
                    break;
                case '1':
                    if(currentNode->one == nullptr) {
                        currentNode->one = new Node();
                        currentNode->one->root = currentNode->root;
                    }
                    currentNode = currentNode->one;
                    break;
            }
            if(currentNode->star == true) break;
        }
        currentNode->end = true;
    }

    activeIPs = currentNode->root;

    cin >> m;
    getline(cin, s);

    rep(i,m) {
        getline(cin, s);
        currentNode = currentNode->root;
        bool end = false;
        for(char c: s) {
            if(currentNode->star) {
                break;
            }

            switch (c) {
                case '0':
                    if(currentNode->zero == nullptr) {
                        end = true;
                        break;
                    }
                    currentNode = currentNode->zero;
                    break;
                case'1':
                    if(currentNode->one == nullptr) {
                        end = true;
                        break;
                    }
                    currentNode = currentNode->one;
                    break;
            }
            if(end) break;
        }

        if(!end && (currentNode->end || currentNode->star)) {
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }


    return 0;
}

