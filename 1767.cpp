#include <iostream>
#include <vector>
 
#define inf 1e9
using namespace std;
 
class Pos {
public:
    int row, col, dir = 0;
    Pos(int row, int col) {
        this->row = row;
        this->col = col;
    }
};
 
int N, T, board[20][20], dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 }, maxConnected, minUsed;
vector<Pos> vt;
 
int draw(int row, int col, int dir, vector<pair<int, int>>& memo) {
    int usedWire = 0;
    pair<int, int> inp;
    while (true) {
        row += dx[dir];
        col += dy[dir];
        if (row < 0 || N <= row || col < 0 || N <= col) break;
        if (board[row][col] != 0) {
            for (auto& m : memo) board[m.first][m.second] = 0;
            return -1;
        }
        inp.first = row;
        inp.second = col;
        memo.emplace_back(inp);
        usedWire++;
        board[row][col] = 1;
    }
    return usedWire;
}
 
void solv(int level, int cnt, int sum) {
    if (level == vt.size()) {
        if (maxConnected < cnt) {
            maxConnected = cnt;
            minUsed = sum;
        }
        else if (maxConnected == cnt) minUsed = min(minUsed, sum);
        return;
    }
    bool flag = true;
    int tmp = vt.size() - level + cnt;
    if (tmp < maxConnected) return;
    if (vt[level].row == 0 || vt[level].row == N - 1 || vt[level].col == 0 || vt[level].col == N - 1) solv(level + 1, cnt + 1, sum);
    else {
        for (int i = 0; i < 4; ++i) {
            vector<pair<int, int>> memo;
            vt[level].dir = i;
            int flag = draw(vt[level].row, vt[level].col, vt[level].dir, memo);
            if (flag != -1) {
                solv(level + 1, cnt + 1, sum + flag);
                flag = false;
            }
            for (auto& m : memo) {
                board[m.first][m.second] = 0;
            }
        }
    }
    if (flag) solv(level + 1, cnt, sum);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> N;
        minUsed = 1e9;
        maxConnected = -1;
        vt.clear();
 
        int inputs;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> inputs;
                if (inputs) {
                    Pos p(i, j);
                    vt.emplace_back(p);
                    board[i][j] = 2;
                }
                else board[i][j] = 0;
            }
        }
        solv(0, 0, 0);
        cout << "#" << tc << " " << minUsed << '\n';
    }
}