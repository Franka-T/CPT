#include <vector>
#include <iostream>
#include <queue>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int> >;
using ll = long long;


struct position {
    int h;
    int w;

    position(){}

    position(int x, int y) {
        h = x;
        w = y;
    }
};

struct out {
    bool visited = false;
    position vorgaenger;
};

bool validPosition(vector<vector<char> > &board, int x, int y) {
    int h = board.size();
    int w = board[0].size();

    if((x >= 0 && x < h && y >= 0 && y < w)) {
        if(board[x][y] != 'x') return true;
    }

    return false;
}

bool addNode(int x, int y, position currentNode, position startNode, vector<vector<char> > &board, vector<vector<out> > &visited, queue<position> &todo){
    if(!validPosition(board, x, y) || visited[x][y].visited) return false;
    position newNode(x,y);
    visited[x][y].visited = true;
    visited[x][y].vorgaenger = currentNode;
    //visited[x][y].push_back(newNode);
    todo.push(newNode);

    if(board[x][y] == 'N'){
        visited[startNode.h][startNode.w].vorgaenger = newNode;
        return true;
    }
    return false;

}

vector<vector<out> > bfs(vector<vector<char> > &board, position startNode) {
    int h = board.size();
    int w = board[0].size();

    vector<vector<out> > visited (h, vector<out>(w));
    queue<position> todo;

    visited[startNode.h][startNode.w].visited = true;
    todo.push(startNode);

    while(!todo.empty()) {
        position currentNode = todo.front();
        todo.pop();

        int x = currentNode.h;
        int y = currentNode.w;

        if(addNode(x-2, y-1, currentNode, startNode, board, visited, todo)) return visited;
        if(addNode(x-2, y+1, currentNode, startNode, board, visited, todo)) return visited;
        if(addNode(x-1, y+2, currentNode, startNode, board, visited, todo)) return visited;
        if(addNode(x+1, y+2, currentNode, startNode, board, visited, todo)) return visited;
        if(addNode(x+2, y+1, currentNode, startNode, board, visited, todo)) return visited;
        if(addNode(x+2, y-1, currentNode, startNode, board, visited, todo)) return visited;
        if(addNode(x+1, y-2, currentNode, startNode, board, visited, todo)) return visited;
        if(addNode(x-1, y-2, currentNode, startNode, board, visited, todo)) return visited;
    }

    visited[startNode.h][startNode.w].vorgaenger = position( -1, -1);

    return visited;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int w, h;
    cin >> w >> h;

    vector<vector<char> > board(h, vector<char>(w));

    position king;

    for(int i = h - 1; i >= 0; i --) {
        string s;
        cin >> s;
        rep(j, w) {
            switch (s[j]) {
                case 'K': board[i][j] = 'x'; break;
                case 'Q': board[i][j] = 'x'; break;
                case 'B': board[i][j] = 'x'; break;
                case 'P': board[i][j] = 'x'; break;
                case 'R': board[i][j] = 'x'; break;
                case 'k': king.h= i; king.w = j;
                default: board[i][j] = s[j];
            }
        }
    }

    vector<vector<out> > out = bfs(board, king);
    position node = out[king.h][king.w].vorgaenger;

    if(node.h == -1) {
        cout << "Resign" << endl;
    }else{
        vector<position> path;
        while(node.h != king.h || node.w != king.w) {
            path.push_back(node);
            node = out[node.h][node.w].vorgaenger;
        }
        path.push_back(king);

        cout << "Checkmate in " << path.size() - 1 << endl;
        rep(i, path.size()-1) {
            cout << path[i].h + 1 << " " << path[i].w + 1 << " " << path[i + 1].h + 1<< " " << path[i + 1].w + 1 << endl;
        }
    }

    return 0;
}

